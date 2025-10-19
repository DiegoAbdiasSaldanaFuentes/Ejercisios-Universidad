class User{
  final String title;
  final String first;
  final String last;
  final String email;
  final String path;


  User({
    required this.title,
    required this.first,
    required this.last,
    required this.email,
    required this.path
  });

  factory User.fromJSON(Map<String, dynamic> json){
    return User(
      title: json['name']['title'], 
      first: json['name']['first'], 
      last: json['name']['last'], 
      email: json['email'],
      path: json['picture']['medium']);
  }

}