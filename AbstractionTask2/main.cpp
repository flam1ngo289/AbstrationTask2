#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int numHouse;
    int numFlat;
    
public:
    Address(std::string city, std::string street, int numHouse, int numFlat) {
        this->city = city;
        this->street = street;
        this->numHouse = numHouse;
        this->numFlat = numFlat;
    }
    
    std::string get_output_adress(){
        return city + ", " + street + ", " + std::to_string(numHouse) + ", " + std::to_string(numFlat);
    }
};

void sort(Address* address[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (address[i]->get_output_adress() < address[j]->get_output_adress()) {
                Address* temp = address[i];
                address[i] = address[j];
                address[j] = temp;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    
    std::ifstream infile("in.txt"); //open file to read
    std::ofstream outfile ("out.txt");
    
    int n;
    infile >> n; // first word in the file
    
    Address** address = new Address*[n];
    
    for (int i = 0; i < n; i++) {
        std::string city, street;
        int numHouse, numFlat;
        
        infile >> city >> street >> numHouse >> numFlat;
        address[i] = new Address(city, street, numHouse, numFlat);
    }
    
    sort(address, n);
    
    outfile << n << std::endl;
    
    for (int i = n -1; i >= 0; i--) {
        outfile << address[i]->get_output_adress() << std::endl;
    }

    for (int i = 0; i < n; i++) {
        delete address[i];
    }
    
    delete[] address;
    
    infile.close();
    outfile.close();
    
    return 0;
}
