import 'package:flutter/material.dart';

//model class for each news item retrieved from API
class NewsItem {
  String providerName;
  String title;
  String description;
  String url;
  String imageUrl;
  String time;

  NewsItem({
    @required this.providerName,
    @required this.description,
    @required this.imageUrl,
    @required this.title,
    @required this.time,
    @required this.url,
  });
}
