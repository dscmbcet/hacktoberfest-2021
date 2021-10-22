import 'package:flutter/material.dart';
import 'package:news_flutter/utilities/news_item.dart';
import 'package:url_launcher/url_launcher.dart';
import 'package:intl/intl.dart';

class NewsItemWidget extends StatelessWidget {
  final NewsItem newsItem;

  NewsItemWidget(this.newsItem);

  //open urls
  _launchURL(String url) async {
    if (await canLaunch(url)) {
      await launch(url);
    } else {
      throw 'Could not launch $url';
    }
  }

  @override
  Widget build(BuildContext context) {
    return Card(
      child: Padding(
        padding: EdgeInsets.all(8.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.stretch,
          children: [
            Text(
              newsItem.title ?? '',
              style: TextStyle(
                  fontFamily: 'roboto',
                  fontSize: 22,
                  fontWeight: FontWeight.bold),
            ),
            SizedBox(
              height: 10,
            ),
            Text(
              newsItem.providerName ?? '',
              textAlign: TextAlign.right,
              style: TextStyle(
                  fontFamily: 'roboto',
                  fontSize: 18,
                  color: Colors.blueAccent,
                  fontStyle: FontStyle.italic),
            ),
            SizedBox(
              height: 10,
            ),
            Text(
              newsItem.description ?? '',
              style: TextStyle(
                fontFamily: 'roboto',
                fontSize: 16,
              ),
            ),
            Padding(
                padding: EdgeInsets.all(10),
                child: Image.network(newsItem.imageUrl ?? '')),
            TextButton(
              onPressed: () {
                _launchURL(newsItem.url ?? '');
              },
              child: Text(
                newsItem.url,
                textAlign: TextAlign.left,
                style: TextStyle(
                    decoration: TextDecoration.underline, color: Colors.blue),
              ),
            ),
            SizedBox(
              height: 10,
            ),
            Text(
              toDateFormat(newsItem.time) ?? '',
              textAlign: TextAlign.right,
              style: TextStyle(
                  fontFamily: 'roboto', fontSize: 18, color: Colors.white70),
            ),
          ],
        ),
      ),
    );
  }
}

String toDateFormat(String time) {
  DateTime postedOn = DateTime.parse(time);
  String output =
      "${DateFormat('hh:mm a').format(postedOn)}, ${postedOn.day}${getDayOfMonthSuffix(postedOn.day)} ${months[postedOn.month-1]}";
  return output;
}

String getDayOfMonthSuffix(int dayNum) {
  if (!(dayNum >= 1 && dayNum <= 31)) {
    throw Exception('Invalid day of month');
  }

  if (dayNum >= 11 && dayNum <= 13) {
    return 'th';
  }

  switch (dayNum % 10) {
    case 1:
      return 'st';
    case 2:
      return 'nd';
    case 3:
      return 'rd';
    default:
      return 'th';
  }
}

List<String> months = [
  'Jan',
  'Feb',
  'Mar',
  'Apr',
  'May',
  'Jun',
  'Jul',
  'Aug',
  'Sep',
  'Oct',
  'Nov',
  'Dec',
];