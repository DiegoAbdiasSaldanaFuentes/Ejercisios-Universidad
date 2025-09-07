import 'package:flutter/material.dart';
import 'package:fonda/model/product.dart';

class ItemProduct extends StatelessWidget {
  const ItemProduct({super.key, required this.product});
  final Product product;

  @override
  Widget build(BuildContext context) {
    return Container(
      child: Text('Tarea'),
    );
  }
}
