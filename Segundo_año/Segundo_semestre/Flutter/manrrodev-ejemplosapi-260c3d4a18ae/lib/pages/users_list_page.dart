import 'package:ejemplosapi/model/user.dart';
import 'package:ejemplosapi/service/api.dart';
import 'package:flutter/material.dart';
import 'package:lottie/lottie.dart';

class UserListPage extends StatelessWidget {
  const UserListPage({super.key});

  @override
  Widget build(BuildContext context) {
    Api api = Api();

    return Scaffold(
      backgroundColor: Colors.amber[100],
      appBar: AppBar(
        title: Text('Usuarios'),
        centerTitle: true,
        elevation: 0,
        backgroundColor: Colors.transparent,
        scrolledUnderElevation: 0,
      ),
      body: Column(
        children: [
          Text('Lista de Usuarios'),
          SizedBox(height: 20,),
          Expanded(
            child: FutureBuilder(
              future: api.fetchUsers(), 
              builder: (context, snapshot){
                if(snapshot.connectionState==ConnectionState.done){
                    
                  List<User> list = snapshot.data??[];

                  return ListView.builder(
                    itemCount: list.length,
                    itemBuilder: (context, index){
                      return ListTile(
                        //leading: Image.network(list[index].path),
                        leading: ClipOval(
                          child: Image.network(list[index].path),
                        ),
                        title: Text(list[index].title+' '+ list[index].first+' ' +list[index].last),
                        subtitle: Text(list[index].email),

                      );
                    }
                  );

                }else{
                  return Center(child: Lottie.asset('images/loading.json'),);
                }
              }
            ),
          )
        ],
      ),
    );
  }
}