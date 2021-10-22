import 'package:flutter/material.dart';
import 'package:news_flutter/components/news_item_widget.dart';
import 'package:news_flutter/utilities/news_item.dart';
import 'package:news_flutter/utilities/networking.dart';

class MainScreen extends StatefulWidget {
  @override
  _MainScreenState createState() => _MainScreenState();
}

class _MainScreenState extends State<MainScreen> {
  bool showSpinner;
  List<NewsItem> newsItems = [];
  @override
  void initState() {
    super.initState();
    getNewsData();
  }

  //populate news items
  void getNewsData() async {
    setState(() {
      showSpinner = true;
    });
    await NetworkHelper.getConversion(newsItems);
    print(newsItems[0].providerName);
    setState(() {
      showSpinner = false;
    });
  }

  @override
  Widget build(BuildContext context) {
    //spinner shown while retrieving data from API
    if (showSpinner) {
      return Scaffold(
        appBar: AppBar(
          title: Text(
            'News',
            style: TextStyle(
              fontFamily: 'roboto',
            ),
          ),
        ),
        body: Center(
          child: CircularProgressIndicator(),
        ),
      );
    }
    return Scaffold(
      appBar: AppBar(
        actions: [
          //refresh button used to make a fresh API call and get updated data
          IconButton(
            onPressed: () {
              getNewsData();
            },
            icon: Icon(
              Icons.refresh,
              color: Colors.white,
            ),
          )
        ],
        title: Text(
          'News',
          style: TextStyle(
            fontFamily: 'roboto',
          ),
        ),
      ),
      body: Padding(
        padding: EdgeInsets.all(12.0),
        child: ListView.builder(
          physics: BouncingScrollPhysics(),
          itemCount: newsItems.length + 1,
          itemBuilder: (context, index) {
            if (index == newsItems.length) {
              return Container(
                width: MediaQuery.of(context).size.width,
                height: 50,
                child: Center(
                  child: Text(
                    'All Caught Up',
                    style: TextStyle(fontFamily: 'roboto', fontSize: 20),
                  ),
                ),
              );
            }
            return NewsItemWidget(newsItems[index]);
          },
        ),
      ),
    );
  }
}
