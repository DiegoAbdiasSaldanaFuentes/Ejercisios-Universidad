import 'package:ejemplosapi/pages/users_list_page.dart';
import 'package:flutter/material.dart';

class MainListPage extends StatelessWidget {
  const MainListPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('App Api'),
        centerTitle: true,
      ),
      body:ListView(
        children: [
          ListTile(
            title: Text('Usuarios'),
            leading: Icon(Icons.check),
            onTap: (){
              Navigator.push(
                context, 
                MaterialPageRoute(builder: (context)=>UserListPage()));
            },
          ),
          ListTile(
            title: Text('Mondedas'),
            leading: Icon(Icons.check),
            onTap: (){

            },
          ),
        ],
      )
    );
  }
}