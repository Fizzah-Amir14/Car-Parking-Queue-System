#include <iostream>
#include <string>
using namespace std;

class Parking {
public:
    struct carRecord {
        string carNo;
        string arrivalTime;
        int slotNo;
    };

private:
    carRecord* arr;
    int size;
    int front;
    int rear;
    int capacity;

public:
    Parking() {
        capacity = 10;
        arr = new carRecord[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    Parking(int cap) {
        capacity = (cap > 0) ? cap : 10;
        arr = new carRecord[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Parking() {
        delete[] arr;
    }

    bool is_empty(){
        return size==0;
    }

    bool is_full() {
        return size==capacity;
    }

    void parkCar(carRecord &r){
        if(is_full()){
            cout<<"Queue is full!!"<<endl;
            return;
        } else{
            rear=(rear+1)%capacity;
            arr[rear]=r;
            size++;
        }
    }

    carRecord removeCar() {
        if(is_empty()){
            cout<<"Queue is empty!!"<<endl;
            return {"","",0};
        } else{
            front=(front+1)%capacity;
            carRecord r=arr[front];
            size--;
            return r;
        }
    }

    void displayParkingStatus(){
        if(is_empty()){
            cout<<"Queue is empty."<<endl;
            return;
        }
        for(int i=front;i<=rear;i++){
            cout<<"Car No: "<<arr[i].carNo<<" Arrival Time: "<<arr[i].arrivalTime<<" Slot Number: "<<arr[i].slotNo<<endl;
        }
        // cout<<"Parking History Printed Successfully "<<endl;
    }
};

int main() {
    Parking p1;
    Parking p2(6);

    Parking::carRecord r1={"ABC-123", "09:00 AM", 1};
    Parking::carRecord r2={"XYZ-456", "09:15 AM", 2};
    Parking::carRecord r3={"LMN-789", "09:30 AM", 3};
    Parking::carRecord r4={"DEF-321", "09:45 AM", 4};

    cout<<"Car Parking:"<<endl;
    p1.parkCar(r1);
    p1.parkCar(r2);
    p2.parkCar(r3);
    p2.parkCar(r4);
     p1.displayParkingStatus();
    p2.displayParkingStatus();
    cout<<"Car Removing:"<<endl;
    p1.removeCar();
    p2.removeCar();

    cout<<"Display Parking Status After Car Removal:"<<endl;
    p1.displayParkingStatus();
    p2.displayParkingStatus();

    return 0;
}
