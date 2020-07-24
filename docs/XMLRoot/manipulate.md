void set_element(string el);
string get_element();

void set_text(string tx);
string get_text();
int length_text();
int length_text_without_wihtespace();

void add_attribut(string att);
void set_attribut(string att,int id);
string get_attribut(int id);
int length_attribut();

void add_value(string val);
void set_value(string val,int id);
string get_value(int id);
int length_value();

XMLRoot * get_parent();
void set_parent(XMLRoot * new_parent);

void add_root(XMLRoot val);
void set_root(XMLRoot val,int id);
XMLRoot * get_root(int id);
XMLRoot * get_root();
int length_root();