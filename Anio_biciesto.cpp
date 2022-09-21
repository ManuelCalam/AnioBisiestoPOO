#include <iostream>
#include <string.h>

class Date{
    private:
        std::string Fecha, auxFecha;
        int day, month, year, bisiesto;

    public:
        Date(std::string);

        void verifyYear(){      
            if((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year %
                400 == 0)){
                std::cout<<"Anio bisiesto"<<std::endl;
                bisiesto = 1;
            }

            else{
                std::cout<<"Anio no bisiesto"<<std::endl;
                bisiesto = 0;
            }

            std::cout<<"Anio: ";
            std::cout<<year<<std::endl;
        }

        void verifyMonth(){
            if (month < 1 || month > 12)
            {
                std::cout<<"Mes invalido, cambiando por defecto a Noviembre..."<<std::endl;
                month = 11;
            }

            std::cout<<"Mes: ";
            std::cout<<month<<std::endl;
        }

        void verifyDay(){

            //Meses con 31 dias
            if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 31)){
                std::cout<<"Dia invalido, cambiando por defecto a 17..."<<std::endl;
                day = 17;
            }

            //Febrero
            if ((month == 2 && bisiesto == 0) && (day < 1 || day > 28)){
                std::cout<<"Dia invalido, cambiando por defecto a 28..."<<std::endl;
                day = 28;
            }
            else if ((month == 2 && bisiesto == 1) && (day < 1 || day > 29)){
                std::cout<<"Dia invalido, cambiando por defecto a 29..."<<std::endl;
                day = 29;
            }

            //Meses con 30 dias
            if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)){
                std::cout<<"Dia invalido, cambiando por defecto a 30..."<<std::endl;
                day = 30;
            }
            

            std::cout<<"Dia: ";
            std::cout<<day<<std::endl;
        }

        

        

        
        

};

Date::Date(std::string _Fecha){
    Fecha = _Fecha;

    auxFecha = _Fecha.substr(0, 4);
    year = stoi(auxFecha);

    
    auxFecha = Fecha.substr(5, 6);
    month = stoi(auxFecha);

    auxFecha = Fecha.substr(8, 9);
    day = stoi(auxFecha);

    verifyYear();
    verifyMonth();
    verifyDay();
}



int main(){

    std::string _date;
    std::cout<<"Ingresar fecha en formato YYYY/MM/DD:"<<std::endl;
    getline(std::cin, _date);
    std::cout<<std::endl;
    
    
    Date objFecha(_date);

}


