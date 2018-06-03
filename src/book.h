#ifndef BOOK_H
#define BOOK_H
class Book{
public:
  Book(std::string const &title,std::string const &author,int price){
    _title = title;
    _author = author;
    _price = price;
  }

  Book(){
    _title = "";
    _author = "";
    _price = 0;
  }

  std::string title() const{
    return _title;
  }

  std::string author() const{
    return _author;
  }

  int price() const{
    return _price;
  }

  bool operator ==(Book const&k) const{
    if(this->title() == k._title && this->author() == k._author && this->price() == k._price){
      return 1;
    }
    else{
      return 0;
    }
  }

  // Book operator =(Book const&k) {
  //   _title = k.title();
  //   _author = k.author();
  //   _price = k.price();
  //   return *this;
  // }

private:
  std::string _title;
  std::string _author;
  int _price;
};
#endif
