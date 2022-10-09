#include <string>
using namespace std;
class Parovozik_Tomas {
protected:
    int capacity;//вместимость
    int ticket_price_up, ticket_price_down;//стоимость билета верхнего и нижнего места
    string type;
public:
    Parovozik_Tomas(int a, int b, int c, string d);
    void set_capacity(int a);
    void set_ticket_price_up(int a);
    void set_ticket_price_down(int a);
    int get_capacity();
    int get_ticket_price_up();
    int get_ticket_price_down();
    string get_type();
    void print_vagon();
};

class Plac : public Parovozik_Tomas {//плацкарт
protected:
    int top_positions_occupied;
    int down_positions_occupied;//занятые места сверху и снизу
    int entry_year;//год ввода в эксплуатацию
public:
    Plac(int a, int b, int c, string d, int f, int e , int g);
    void price();
    void check_positions_occupied();
    void set_top_positions_occupied(int a);
    void set_down_positions_occupied(int a);
    int get_top_positions_occupied();
    int get_down_positions_occupied();
    int get_entry_year();
    void print();
};

class Sid : public Parovozik_Tomas {//сидячие
protected:
    int number_passengers;//количество пассажиров
    int entry_year;//год ввода в эксплуатацию
public:
    Sid(int a, int b, int c, string d, int f, int e);
    void set_number_passengers(int a);
    int get_number_passengers();
    int get_entry_year();
    void price();
    void print();
};

class Kup : public Parovozik_Tomas {//купэ
protected:
    int top_positions_occupied, down_positions_occupied;//занятые места сверху и снизу
    int entry_year;//год ввода в эксплуатацию
public:
    Kup(int a, int b, int c, string d, int f, int e, int g);
    void price();
   // Kup() = default;
    void set_top_positions_occupied(int a);
    void set_down_positions_occupied(int a);
    int get_top_positions_occupied();
    int get_down_positions_occupied();
    int get_entry_year();
    void print();
};
/****************************************           Конструкторы          ************************************/
Parovozik_Tomas::Parovozik_Tomas(int capacity = 30, int ticket_price_up = 20, int ticket_price_down = 25, string type = "Без типа") {
    this->capacity = capacity;
    this->ticket_price_up = ticket_price_up;
    this->ticket_price_down = ticket_price_down;
    this->type = type;
}

Plac::Plac(int capacity = 54, int ticket_price_up = 2100, int  ticket_price_down = 2500, string type = "Плацкарт", int top_positions_occupied = 25, int down_positions_occupied = 27, int entry_year = 2001) :Parovozik_Tomas(capacity, ticket_price_up, ticket_price_down, type) {
    this->top_positions_occupied = top_positions_occupied;
    this->down_positions_occupied = down_positions_occupied;
    this->entry_year = entry_year;
}

Sid::Sid(int capacity = 68, int ticket_price_up = 0, int  ticket_price_down = 1500, string type = "Сидячий вагон", int number_passengers = 59, int entry_year = 2014) :Parovozik_Tomas(capacity, ticket_price_up, ticket_price_down, type) {
    this->number_passengers = number_passengers;
    this->entry_year = entry_year;
}

Kup::Kup(int capacity = 36, int ticket_price_up = 3100, int  ticket_price_down = 2800, string type = "Купе", int top_positions_occupied = 16, int down_positions_occupied = 18, int entry_year = 2009) :Parovozik_Tomas(capacity, ticket_price_up, ticket_price_down, type) {
    this->top_positions_occupied = top_positions_occupied;
    this->down_positions_occupied = down_positions_occupied;
    this->entry_year = entry_year;
}
/****************************************           Сеттеры и геттеры        ************************************/
void Parovozik_Tomas::set_capacity(int a) {
    capacity = a;
}

void Parovozik_Tomas::set_ticket_price_up(int a) {
    ticket_price_up = a;
}

void Parovozik_Tomas::set_ticket_price_down(int a) {
    ticket_price_down = a;
}

int Parovozik_Tomas::get_capacity() {
    return capacity;
}

int Parovozik_Tomas::get_ticket_price_up() {
    return ticket_price_up;
}

int Parovozik_Tomas::get_ticket_price_down() {
    return ticket_price_down;
}

void Plac::set_top_positions_occupied(int a) {
    top_positions_occupied = a;
}

void Plac::set_down_positions_occupied(int a) {
    down_positions_occupied = a;
}

int Plac::get_top_positions_occupied() {
    return top_positions_occupied;
}

int Plac::get_down_positions_occupied() {
    return down_positions_occupied;
}

void Sid::set_number_passengers(int a) {
    number_passengers = a;
}

int Sid::get_number_passengers() {
    return number_passengers;
}

void Kup::set_top_positions_occupied(int a) {
    top_positions_occupied = a;
}

void Kup::set_down_positions_occupied(int a) {
    down_positions_occupied = a;
}

int Kup::get_top_positions_occupied() {
    return top_positions_occupied;
}

int Kup::get_down_positions_occupied() {
    return down_positions_occupied;
}

string Parovozik_Tomas::get_type() {
    return type;
}

int Plac::get_entry_year() {
    return entry_year;
}

int Sid::get_entry_year() {
    return entry_year;
}

int Kup::get_entry_year() {
    return entry_year;
}
/****************************************           Вывод параметров на экран        ************************************/
void Parovozik_Tomas::print_vagon() {
    cout << "\nТип вагона: " << get_type() << "\nВместимость: " << get_capacity() << "\nСтоимость билета сверху: " << get_ticket_price_up() <<
        "\nСтоимость билета снизу: " << get_ticket_price_down() << endl;
}

void Plac::print() {
    print_vagon();
    cout << "\nЗанятые места сверху: " << get_top_positions_occupied() << "\nЗанятые места снизу: "
        << get_down_positions_occupied() << "\nГод начала эксплуатации вагона: " << entry_year << endl;
}

/*void Plac::print() {
    cout << "\nТип вагона: " << get_type() << "\nВместимость: " << get_capacity() << "\nСтоимость билета сверху: " << get_ticket_price_up() <<
        "\nСтоимость билета снизу: " << get_ticket_price_down() << "\nЗанятые места сверху: " << get_top_positions_occupied() << "\nЗанятые места снизу: "
        << get_down_positions_occupied() << "\nГод начала эксплуатации вагона: " << entry_year << endl;
}*/

void Sid::print() {
    print_vagon();
    cout << "\nКоличество пассажиров: " << get_number_passengers()
        << "\nГод начала эксплуатации вагона: " << entry_year << endl;
}

void Kup::print() {
    print_vagon();
    cout << "\nЗанятые места сверху: " << get_top_positions_occupied() << "\nЗанятые места снизу: "
        << get_down_positions_occupied() << "\nГод начала эксплуатации вагона: " << entry_year << endl;
}
/****************************************           Подсчет стоимости        ************************************/
void Plac::price() {
    cout << "Прибыль с этого вагона равна " << get_down_positions_occupied() * get_ticket_price_down() + get_top_positions_occupied() * get_ticket_price_up() << endl;
}

void Sid::price() {
    cout << "Прибыль с этого вагона равна " << get_ticket_price_down() * get_number_passengers() << endl;
}

void Kup::price() {
    cout << "Прибыль с этого вагона равна " << get_down_positions_occupied() * get_ticket_price_down() + get_top_positions_occupied() * get_ticket_price_up() << endl;
}
/****************************************           Доп функционал       ************************************/

void Plac::check_positions_occupied() {
    string buf;
    for(;;) {
        if (get_down_positions_occupied <= get_capacity/2 && get_top_positions_occupied <= get_capacity/2 ) {
            break;
        }
        cout << "Количество занятых мест сверху или снизу не может превышать "  << get_capacity/2 << endl;
        cout << "Количество  "
    }
}
