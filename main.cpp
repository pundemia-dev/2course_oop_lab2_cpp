#include <iostream>

using namespace std;

class Point{
    private:
        int *x = new int;
        int *y = new int;
        static int counter;
    public:
        Point() : x(new int(0)), y(new int(0)), id(new int(++counter)){
            printf("[log] Объект класса без параметров создан (id = %d)\n", *id);
        }
        Point(const int &inp_x, const int &inp_y) : x(new int(inp_x)), y(new int(inp_y)), id(new int(++counter)){
            printf("[log] Объект класса с параметрами (x = %d, y = %d) создан (id = %d)\n", *x, *y, *id);
        }
        Point(const Point &p) : x(new int(*p.x)), y(new int(*p.y)), id(new int(++counter)){
            printf("[log] Объект класса с параметром-объектом (x = %d, y = %d) создан (id = %d)\n", *x, *y, *id);
        }

        void setX(const int &inp_x){
            *x = inp_x;
            printf("[log] Задан x = %d (id = %d)\n", *x, *id);
        }
        void setY(const int &inp_y){ 
            *y = inp_y;
            printf("[log] Задан y = %d (id = %d)\n", *y, *id);
        }
        void setXY(const int &inp_x, const int &inp_y){
            *x = inp_x, *y = inp_y;
            printf("[log] Задана позиция x = %d, y = %d (id = %d)\n", *x, *y, *id);
        }
        int getX(){
            return(*x);
        }
        int getY(){
            return (*y);
        }
        ~Point();
    protected:
        int *id = new int;
};

Point::~Point(){
    printf("[log] Вызван деструктор id = %d\n", *id);
    delete x;
    delete y;
    delete id;
}

int Point::counter = 0;

int main(){
    // Static objects
    Point s_point_without_params;
    Point s_point_with_params(1, 2);
    Point s_point_with_object_param(s_point_with_params);
    
    //printf("[log] Пытаемся достать private значение класса: x = %d", s_point_with_params.x);
    //printf("[log] Пытаемся достать protected значение класса: id = %d", s_point_with_params.id);

    s_point_with_params.setX(3);
    s_point_with_params.setY(4);
    s_point_with_params.setXY(5, 6);
    printf("[log] Получен x для точки (x = %d)\n", s_point_with_params.getX());
    printf("[log] Получен y для точки (y = %d)\n", s_point_with_params.getY());

    // Dynamic objects
    Point *d_point_without_params = new Point;
    Point *d_point_with_params = new Point(3, 4);
    Point *d_point_with_object_param = new Point(*d_point_with_params);

    d_point_with_params->setX(3);
    d_point_with_params->setY(4);
    d_point_with_params->setXY(5, 6);
    printf("[log] Получен x для точки (x = %d)\n", d_point_with_params->getX());
    printf("[log] Получен y для точки (y = %d)\n", d_point_with_params->getY());

    delete d_point_without_params;
    delete d_point_with_params;
    delete d_point_with_object_param;
}
