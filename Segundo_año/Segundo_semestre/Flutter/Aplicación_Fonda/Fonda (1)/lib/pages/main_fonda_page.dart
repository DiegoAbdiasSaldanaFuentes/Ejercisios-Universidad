import 'dart:html';

import 'package:flutter/material.dart';
import 'package:fonda/components/card_promos.dart';
import 'package:fonda/components/item_product.dart';
import 'package:fonda/data/data.dart';

class MainFondaPages extends StatelessWidget {
  const MainFondaPages({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey[100],
      appBar: AppBar(
        title: Text('Fonda'),
        actions: [
          IconButton(onPressed: () {}, icon: Icon(Icons.shopping_cart))
        ],
        // leading: Icon(Icons.menu),
      ),
      drawer: Drawer(),
      body: SingleChildScrollView(
          child: Padding(
        padding: EdgeInsets.symmetric(horizontal: 20),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            //promo
            CardPromo(),
            SizedBox(
              height: 18,
            ),
            //Titulo
            Text('Menu Comida'),
            //Listview
            Container(
              height: 200,
              child: ListView.builder(
                scrollDirection: Axis.horizontal,
                itemCount: products.length,
                itemBuilder: (context, index) {
                  return ItemProduct(product: products[index]);
                },
              ),
            )
            //title comida popular
            //card parillada
          ],
        ),
      )),
    );
  }
}
