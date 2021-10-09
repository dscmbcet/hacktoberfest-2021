import 'dart:convert';

import 'package:http/http.dart' as http;
import 'package:news_flutter/utilities/news_item.dart';

//change the api request here
const String url =
    'http://newsapi.org/v2/top-headlines?country=in&category=sports&apiKey=aa67d8d98c8e4ad1b4f16dbd5f3be348';

//manages all networking activities
class NetworkHelper {
  static Future<void> getConversion(List<NewsItem> newsItems) async {
    print('getting to network helper');
    http.Response response = await http.get(url);
    //handle error
    if (response.statusCode != 200) {
      print(response.statusCode);
    } else {
      var decodedData = jsonDecode(response.body);
      int results = decodedData['totalResults'];
      print(results);
      //extract data from json data
      for (var singleItem in decodedData['articles']) {
        String providerName = singleItem['author'];
        String title = singleItem['title'];
        String description = singleItem['description'];
        String url = singleItem['url'];
        String imageUrl = singleItem['urlToImage'];
        String time = singleItem['publishedAt'];
        NewsItem newsItem = NewsItem(
          providerName: providerName,
          description: description,
          imageUrl: imageUrl,
          title: title,
          time: time,
          url: url,
        );
        newsItems.add(newsItem);
      }
    }
  }
}
