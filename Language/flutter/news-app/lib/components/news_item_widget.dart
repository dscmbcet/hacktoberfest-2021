import 'package:flutter/material.dart';
import 'package:news_flutter/utilities/news_item.dart';
import 'package:url_launcher/url_launcher.dart';

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
            FlatButton(
              padding: EdgeInsets.all(0),
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
              newsItem.time ?? '',
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
