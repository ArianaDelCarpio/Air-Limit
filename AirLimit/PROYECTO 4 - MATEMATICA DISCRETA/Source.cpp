#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
using namespace std;
using namespace System;

//variables peru
int filabuscada = -1;
int columnabuscada = -1;

//variables internacionales
int filabuscada_internacional = -1;
int columnabuscada_internacional = -1;

//variables colombia
int filabuscada_colombia = -1;
int columnabuscada_colombia = -1;

//matrices vuelos directos
bool vuelos_peru[9][9] = {
            { false, false, false, false, true, false, false, false, false},
            { false, false, false, false, true, false, false, false, false},
            { false, false, false, false, true, false, false, false, false},
            { false, false, false, false, true, false, false, false, false},
            { true, true, true, true, false, true, true, true, true},
            { false, false, false, false, true, false, true, false, false},
            { false, false, false, false, true, true, false, false, false},
            { false, false, false, false, true, false, false, false, false},
            { false, false, false, false, false, true, false, true, false}

};
bool internacional[25][25] = {
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	true,	false,	false,	false,	true,	false,	false,	false,	true},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	true,	false,	false,	false,	false,	true,	false,	true,	true,	false,	false,	true,	false,	false,	false,	true,	false,	false,	false,	false},
        {false,false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	true,	false,	false,	false,	true},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	true,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	true,	false,	false,	false,	false,	true,	false,	false,	true,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	true,	false,	false,	false,	false,	true,	true,	true,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {true,	true,	true,	true,	true,	false,	false,	false,	false,	true,	true,	false,	false,	false,	true,	true,	true,	false,	false,	true,	true,	true,	true,	true,	true},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	true,	true,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {true,	false,	false,	false,	true,	false,	false,	true,	false,	false,	true,	false,	true,	true,	true,	false,	false,	true,	true,	true,	true,	false,	true,	false,	true},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	true,	false,	false,	false,	true,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	true,	false,	false,	false,	false,	false,	true,	false,	false},
        {true,	false,	true,	false,	true,	false,	true,	true,	true,	false,	false,	false,	false,	true,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	true,	false,	false,	true,	false,	false,	false,	false,	true},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true},
        {true, false, false, false, false, false, false, true, false, false, false, false, false, true, false, false, true, false, false, false, false, false, true, true, false},
};
bool colombia[25][25] = {
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	true,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	true,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	true,	true,	true,	false,	false,	false,	false,	false,	true,	true,	false,	false,	false,	false,	false,	true,	false,	true,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	false,	false,	true,	true,	true,	true,	true,	true,	true},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false},
        {false,	true,	true,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	true,	true,	false,	true,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	true,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
};

//funcioes solo para peru
bool multiplicar_matrices_peru(bool matriz1[9][9], bool matriz2[9][9], bool resultado[9][9])
{
    //inicializamos la matriz resultado
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            resultado[i][j] = false;
        }
    }

    // Multiplicamos las matrices
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                resultado[i][j] = resultado[i][j] || (matriz1[i][k] && matriz2[k][j]);
            }
        }
    }
    return true;
}

void valida_vuelos_peru(string a, string b)
{
    //filas
    {
        if (a == "Piura" || a == "piura" || a == "PIURA")
        {
            filabuscada = 0;
        }
        if (a == "Chiclayo" || a == "chiclayo" || a == "CHICLAYO")
        {
            filabuscada = 1;
        }
        if (a == "Iquitos" || a == "iquitos" || a == "IQUITOS")
        {
            filabuscada = 2;
        }
        if (a == "TRUJILLO" || a == "Trujillo" || a == "trujillo")
        {
            filabuscada = 3;
        }
        if (a == "Lima" || a == "LIMA" || a == "lima")
        {
            filabuscada = 4;
        }
        if (a == "Cusco" || a == "cusco" || a == "CUSCO")
        {
            filabuscada = 5;
        }
        if (a == "Arequipa" || a == "arequipa" || a == "AREQUIPA")
        {
            filabuscada = 6;
        }
        if (a == "Juliaca" || a == "juliaca" || a == "JULIACA")
        {
            filabuscada = 7;
        }
        if (a == "Puerto_Maldonado" || a == "PUERTO_MALDONADO" || a == "puerto_maldonado")
        {
            filabuscada = 8;
        }
    }
    //columnas    
    {
        if (b == "Piura" || b == "piura" || b == "PIURA")
        {
            columnabuscada = 0;
        }
        if (b == "Chiclayo" || b == "chiclayo" || b == "CHICLAYO")
        {
            columnabuscada = 1;
        }
        if (b == "Iquitos" || b == "iquitos" || b == "IQUITOS")
        {
            columnabuscada = 2;
        }
        if (b == "TRUJILLO" || b == "Trujillo" || b == "trujillo")
        {
            columnabuscada = 3;
        }
        if (b == "Lima" || b == "LIMA" || b == "lima")
        {
            columnabuscada = 4;
        }
        if (b == "Cusco" || b == "cusco" || b == "CUSCO")
        {
            columnabuscada = 5;
        }
        if (b == "Arequipa" || b == "arequipa" || b == "AREQUIPA")
        {
            columnabuscada = 6;
        }
        if (b == "Juliaca" || b == "juliaca" || b == "JULIACA")
        {
            columnabuscada = 7;
        }
        if (b == "Puerto_Maldonado" || b == "PUERTO_MALDONADO" || b == "puerto_maldonado")
        {
            columnabuscada = 8;
        }
    }

}

//VUELOS CON UNA ESCALA VALIDACION PERU Y SOLO PERU
void nombres_con_una_escala(int salida, int llegada)
{
    if (salida == 4 && llegada == 5)
    {
        cout << "Lima -> Arequipa -> Cusco " << endl;
    }
    if (salida == 5 && llegada == 4)
    {
        cout << "Cusco -> Arequipa -> Lima " << endl;
    }
    if (salida == 4 && llegada == 6)
    {
        cout << "Lima -> Cusco -> Arequipa" << endl;
    }
    if (salida == 6 && llegada == 4)
    {
        cout << "Arequipa -> Cusco -> Lima " << endl;
    }
    if (salida == 4 && llegada == 8)
    {
        cout << "Lima -> Cusco -> Puerto_Maldonado" << endl;
    }
    if (salida == 8 && llegada == 4)
    {
        cout << "Puerto_Maldonado -> Cusco -> Lima " << endl;
    }

}
//VUELOS CON DOS ESCALAS VALIDACION PERU Y SOLO PERU
void nombres_con_dos_escalas(int salida, int llegada)
{
    if (salida == 4 && llegada == 0)
    {
        cout << "Lima -> Arequipa -> Lima -> Piura " << endl;
        cout << "Lima -> Cusco -> Lima -> Piura " << endl;
    }
    if (salida == 0 && llegada == 4)
    {
        cout << "Piura -> Lima -> Arequipa -> Lima " << endl;
        cout << "Piura -> Lima -> Cusco -> Lima " << endl;
    }

    if (salida == 4 && llegada == 1)
    {
        cout << "Lima -> Trujillo -> Lima -> Chiclayo " << endl;
        cout << "Lima -> Iquitos -> Lima -> Chiclayo " << endl;
    }
    if (salida == 1 && llegada == 4)
    {
        cout << "Chiclayo -> Lima -> Trujillo -> Lima " << endl;
        cout << "Chiclayo -> Lima -> Iquitos -> Lima " << endl;
    }

    if (salida == 4 && llegada == 2)
    {
        cout << "Lima -> Juliaca -> Lima -> Iquitos " << endl;
        cout << "Lima -> Piura -> Lima -> Iquitos " << endl;
    }
    if (salida == 2 && llegada == 4)
    {
        cout << "Iquitos -> Lima -> Juliaca -> Lima " << endl;
        cout << "Iquitos -> Lima -> Piura -> Lima " << endl;
    }

    if (salida == 4 && llegada == 3)
    {
        cout << "Lima -> Cusco -> Lima -> Trujillo " << endl;
        cout << "Lima -> Chiclayo -> Lima -> Trujillo " << endl;
    }
    if (salida == 3 && llegada == 4)
    {
        cout << "Trujillo -> Lima -> Cusco -> Lima " << endl;
        cout << "Trujillo -> Lima -> Chiclayo -> Lima " << endl;
    }

    if (salida == 4 && llegada == 5)
    {
        cout << "Lima -> Arequipa -> Lima -> Cusco " << endl;
        cout << "Lima -> Iquitos -> Lima -> Cusco " << endl;
    }
    if (salida == 5 && llegada == 4)
    {
        cout << "Cusco -> Lima -> Arequipa -> Lima " << endl;
        cout << "Cusco -> Lima -> Iquitos -> Lima " << endl;
    }

    if (salida == 4 && llegada == 6)
    {
        cout << "Lima -> Juliaca -> Lima -> Arequipa " << endl;
        cout << "Lima -> Iquitos -> Lima -> Arequipa " << endl;
    }
    if (salida == 6 && llegada == 4)
    {
        cout << "Arequipa -> Lima -> Juliaca -> Lima " << endl;
        cout << "Arequipa -> Lima -> Iquitos -> Lima " << endl;
    }

    if (salida == 4 && llegada == 7)
    {
        cout << "Lima -> Trujillo -> Lima -> Juliaca " << endl;
        cout << "Lima -> Iquitos -> Lima -> Juliaca " << endl;
    }
    if (salida == 7 && llegada == 4)
    {
        cout << "Juliaca -> Lima -> Trujillo -> Lima " << endl;
        cout << "Juliaca -> Lima -> Iquitos -> Lima " << endl;
    }

    if (salida == 4 && llegada == 8)
    {
        cout << "Lima -> Arequipa -> Cusco -> Puerto_Maldonado " << endl;

    }
    if (salida == 8 && llegada == 4)
    {
        cout << "Puerto_Maldonado -> Cusco -> Arequipa -> Lima " << endl;

    }

}

void matriz_validad_peru(int filabuscada, int columnabuscada, bool matriznatural[9][9], bool matriz1escala[9][9], bool matriz2escalas[9][9], string llegada)
{
    if (filabuscada == -1 || columnabuscada == -1 || filabuscada > 8 || columnabuscada > 8 || (filabuscada < 9 && columnabuscada == -1) || (filabuscada == -1 && columnabuscada < 9))
    {
        cout << "No existe vuelo disponible a " << llegada << endl;
    }
    else
    {
        if (matriznatural[filabuscada][columnabuscada])
        {
            cout << "* Existe vuelo directo a " << llegada << endl;

        }
        if (matriz1escala[filabuscada][columnabuscada])
        {
            cout << "* Existe vuelo con 1 escala a " << llegada << endl;
            nombres_con_una_escala(filabuscada, columnabuscada);
        }
        if (matriz2escalas[filabuscada][columnabuscada])
        {
            cout << "* Existe vuelo con 2 escalas a " << llegada << endl;
            nombres_con_dos_escalas(filabuscada, columnabuscada);

        }
    }
}

void matriz_validad_lima_provincia(int filabuscada, int columnabuscada, bool matriznatural[9][9], bool matriz1escala[9][9], bool matriz2escalas[9][9], string llegada)
{
    if (filabuscada == -1 || columnabuscada == -1 || filabuscada > 8 || columnabuscada > 8 || (filabuscada < 9 && columnabuscada == -1) || (filabuscada == -1 && columnabuscada < 9))
    {
        cout << "No existe vuelo disponible a " << llegada << endl;
    }
    else
    {
        if (matriznatural[filabuscada][columnabuscada])
        {
            cout << "* Existe vuelo directo a " << llegada << endl;

        }
        if (matriz1escala[filabuscada][columnabuscada])
        {
            cout << "* Existe vuelo con 1 escala a " << llegada << endl;
            nombres_con_una_escala(filabuscada, columnabuscada);
        }
        if (matriz2escalas[filabuscada][columnabuscada])
        {
            cout << "* Existe vuelo con 2 escalas a " << llegada << endl;
            nombres_con_dos_escalas(filabuscada, columnabuscada);

        }
    }
}

void matriz_validad_nacional_alima(int filabuscada, int columnabuscada, bool matriznatural[9][9], bool matriz1escala[9][9], bool matriz2escalas[9][9])
{
    if ((filabuscada == -1 || columnabuscada == -1 || filabuscada > 8 || columnabuscada > 8 || (filabuscada < 9 && columnabuscada == -1) || (filabuscada == -1 && columnabuscada < 9)))
    {
        cout << "No existe vuelo disponible a lima" << endl;
    }
    else
    {
        if (matriznatural[filabuscada][columnabuscada])
        {
            cout << "* Existe vuelo directo a lima" << endl;
        }
        if (matriz1escala[filabuscada][columnabuscada])
        {
            cout << "* Existe vuelo con 1 escala a lima" << endl;
            nombres_con_una_escala(filabuscada, columnabuscada);
        }
        if (matriz2escalas[filabuscada][columnabuscada])
        {
            cout << "* Existe vuelo con 2 escalas a lima" << endl;
            nombres_con_dos_escalas(filabuscada, columnabuscada);
        }
    }
}

//funciones para internacionales 
bool multiplicar_matrices_internacionales(bool matriz[25][25], bool matriz2[25][25], bool resultado[25][25])
{
    //inicializamos la matriz resultado
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            resultado[i][j] = false;
        }
    }
    //multiplicamos las matrices
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            for (int k = 0; k < 25; k++)
            {
                resultado[i][j] = resultado[i][j] || (matriz[i][k] && matriz2[k][j]);
            }
        }
    }
    return true;
}

void validar_vuelos_internacionales(string a, string b)
{
    //filas
    {
        if (a == "Ciudad_de_Mexico" || a == "CIUDAD_DE_MEXICO" || a == "ciudad_de_mexico")
        {
            filabuscada_internacional = 0;
        }
        if (a == "La_Habana" || a == "LA_HABANA" || a == "la_habana")
        {
            filabuscada_internacional = 1;
        }
        if (a == "Cancun" || a == "CANCUN" || a == "cancun")
        {
            filabuscada_internacional = 2;
        }
        if (a == "Belice" || a == "BELICE" || a == "belice")
        {
            filabuscada_internacional = 3;
        }
        if (a == "Ciudad_de_Guatemala" || a == "CIUDAD_DE_GUATEMALA" || a == "ciudad_de_guatemala")
        {
            filabuscada_internacional = 4;
        }
        if (a == "Flores" || a == "FLORES" || a == "flores")
        {
            filabuscada_internacional = 5;
        }
        if (a == "Punta_Cana" || a == "PUNTA_CANA" || a == "punta_cana")
        {
            filabuscada_internacional = 6;
        }
        if (a == "Santo_Domingo" || a == "SANTO_DOMINGO" || a == "santo_domingo")
        {
            filabuscada_internacional = 7;
        }

        if (a == "San_Juan" || a == "SAN_JUAN" || a == "san_juan")
        {
            filabuscada_internacional = 8;
        }
        if (a == "Roatan" || a == "ROATAN" || a == "roatan")
        {
            filabuscada_internacional = 9;
        }
        if (a == "San_Pedro_de_Sula" || a == "SAN_PEDRO_DE_SULA" || a == "san_pedro_de_sula")
        {
            filabuscada_internacional = 10;
        }
        if (a == "La_ceiba" || a == "LA_CEIBA" || a == "la_ceiba")
        {
            filabuscada_internacional = 11;
        }
        if (a == "Tegucigalpa" || a == "TEGUCIGALPA" || a == "tegucigalpa")
        {
            filabuscada_internacional = 12;
        }
        if (a == "San_Salvador" || a == "SAN_SALVADOR" || a == "san_salvador")
        {
            filabuscada_internacional = 13;
        }
        if (a == "Managua" || a == "MANAGUA" || a == "managua")
        {
            filabuscada_internacional = 14;
        }
        if (a == "Liberia" || a == "LIBERIA" || a == "liberia")
        {
            filabuscada_internacional = 15;
        }
        if (a == "San_Jose_de_Costa_Rica" || a == "san_jose_de_costa_rica" || a == "SAN_JOSE_DE_COSTA_RICA")
        {
            filabuscada_internacional = 16;
        }
        if (a == "Ciudad_de_Panama" || a == "ciudad_de_panama" || a == "CIUDAD_DE_PANAMA")
        {
            filabuscada_internacional = 17;
        }
        if (a == "Caracas" || a == "caracas" || a == "CARACAS")
        {
            filabuscada_internacional = 18;
        }
        if (a == "Medellin" || a == "medellin" || a == "MEDELLIN")
        {
            filabuscada_internacional = 19;
        }
        if (a == "Bogota" || a == "bogota" || a == "BOGOTA")
        {
            filabuscada_internacional = 20;
        }
        if (a == "Cali" || a == "cali" || a == "CALI")
        {
            filabuscada_internacional = 21;
        }
        if (a == "Quito" || a == "quito" || a == "QUITO")
        {
            filabuscada_internacional = 22;
        }
        if (a == "Guayaquil" || a == "guayaquil" || a == "GUAYAQUIL")
        {
            filabuscada_internacional = 23;
        }
        if (a == "Lima" || a == "lima" || a == "LIMA")
        {
            filabuscada_internacional = 24;
        }
    }

    //columnas

    {
        if (b == "Ciudad_de_Mexico" || b == "CIUDAD_DE_MEXICO" || b == "ciudad_de_mexico")
        {
            columnabuscada_internacional = 0;
        }
        if (b == "La_Habana" || b == "LA_HABANA" || b == "la_habana")
        {
            columnabuscada_internacional = 1;
        }
        if (b == "Cancun" || b == "CANCUN" || b == "cancun")
        {
            columnabuscada_internacional = 2;
        }
        if (b == "Belice" || b == "BELICE" || b == "belice")
        {
            columnabuscada_internacional = 3;
        }
        if (b == "Ciudad_de_Guatemala" || b == "CIUDAD_DE_GUATEMALA" || b == "ciudad_de_guatemala")
        {
            columnabuscada_internacional = 4;
        }
        if (b == "Flores" || b == "FLORES" || b == "flores")
        {
            columnabuscada_internacional = 5;
        }
        if (b == "Punta_Cana" || b == "PUNTA_CANA" || b == "punta_cana")
        {
            columnabuscada_internacional = 6;
        }
        if (b == "Santo_Domingo" || b == "SANTO_DOMINGO" || b == "santo_domingo")
        {
            columnabuscada_internacional = 7;
        }
        if (b == "San_Juan" || b == "SAN_JUAN" || b == "san_juan")
        {
            columnabuscada_internacional = 8;
        }
        if (b == "Roatan" || b == "ROATAN" || b == "roatan")
        {
            columnabuscada_internacional = 9;
        }
        if (b == "San_Pedro_de_Sula" || b == "SAN_PEDRO_DE_SULA" || b == "san_pedro_de_sula")
        {
            columnabuscada_internacional = 10;
        }
        if (b == "La_ceiba" || b == "LA_CEIBA" || b == "la_ceiba")
        {
            columnabuscada_internacional = 11;
        }
        if (b == "Tegucigalpa" || b == "TEGUCIGALPA" || b == "tegucigalpa")
        {
            columnabuscada_internacional = 12;
        }
        if (b == "San_Salvador" || b == "SAN_SALVADOR" || b == "san_salvador")
        {
            columnabuscada_internacional = 13;
        }
        if (b == "Managua" || b == "MANAGUA" || b == "managua")
        {
            columnabuscada_internacional = 14;
        }
        if (b == "Liberia" || b == "LIBERIA" || b == "liberia")
        {
            columnabuscada_internacional = 15;
        }

        if (b == "San_Jose_de_costa_Rica" || b == "san_jose_de_costa_rica" || b == "SAN_JOSE_DE_COSTA_RICA")
        {
            columnabuscada_internacional = 16;
        }
        if (b == "Ciudad_de_Panama" || b == "ciudad_de_panama" || b == "CIUDAD_DE_PANAMA")
        {
            columnabuscada_internacional = 17;
        }
        if (b == "Caracas" || b == "caracas" || b == "CARACAS")
        {
            columnabuscada_internacional = 18;
        }
        if (b == "Medellin" || b == "medellin" || b == "MEDELLIN")
        {
            columnabuscada_internacional = 19;
        }
        if (b == "Bogota" || b == "bogota" || b == "BOGOTA")
        {
            columnabuscada_internacional = 20;
        }
        if (b == "Cali" || b == "cali" || b == "CALI")
        {
            columnabuscada_internacional = 21;
        }
        if (b == "Quito" || b == "quito" || b == "QUITO")
        {
            columnabuscada_internacional = 22;
        }
        if (b == "Guayaquil" || b == "guayaquil" || b == "GUAYAQUIL")
        {
            columnabuscada_internacional = 23;
        }
        if (b == "Lima" || b == "lima" || b == "LIMA")
        {
            columnabuscada_internacional = 24;
        }

    }
}

// VUELOS CON UNA ESCALA VALIDACION Internacional y solo internacional
void internacional_nombre_con_una_Escala(int salida, int llegada)
{
    if (salida == 24 && llegada == 0)
    {
        cout << "Lima -> San_Salvador -> Ciudad_de_Mexico " << endl;
        cout << "Lima -> San_Jose_de_Costa_Rica -> Ciudad_de_Mexico " << endl;
    }
    if (salida == 0 && llegada == 24)
    {
        cout << "Ciudad_de_Mexico -> San_Salvador -> Lima " << endl;
        cout << "Ciudad_de_Mexico -> San_Jose_de_Costa_Rica -> Lima " << endl;
    }
    if (salida == 24 && llegada == 1)
    {
        cout << "Lima -> San_Salvador -> La_Habana" << endl;
    }
    if (salida == 1 && llegada == 24)
    {
        cout << "La_Habana -> San_Salvador -> Lima " << endl;
    }
    if (salida == 24 && llegada == 2)
    {
        cout << "Lima -> San_Salvador -> Cancun" << endl;
    }
    if (salida == 2 && llegada == 24)
    {
        cout << "Cancun -> San_Salvador -> Lima " << endl;
    }
    if (salida == 24 && llegada == 3)
    {
        cout << "Lima -> San_Salvador -> Belice " << endl;
    }
    if (salida == 3 && llegada == 24)
    {
        cout << "Belice -> San_Salvador -> Lima " << endl;
    }
    if (salida == 24 && llegada == 4)
    {
        cout << "Lima -> San_Salvador -> Ciudad_de_Guatemela" << endl;
        cout << "Lima -> San_Jose_de_Costa_Rica -> Ciudad_de_Guatemela" << endl;
    }
    if (salida == 4 && llegada == 24)
    {
        cout << "Ciudad_de_Guatemela -> San_Salvador -> Lima " << endl;
        cout << "Ciudad_de_Guatemela -> San_Jose_de_Costa_Rica -> Lima" << endl;
    }
    if (salida == 24 && llegada == 7)
    {
        cout << "Lima -> San_Jose_de_Costa_Rica -> Santo_Domingo" << endl;
    }
    if (salida == 7 && llegada == 24)
    {
        cout << "Santo_Domingo -> San_Jose_de_Costa_Rica -> Lima " << endl;
    }
    if (salida == 24 && llegada == 9)
    {
        cout << "Lima -> San_Salvador -> Roatan " << endl;
    }
    if (salida == 9 && llegada == 24)
    {
        cout << "Roatan -> San_Salvador -> Lima " << endl;
    }
    if (salida == 24 && llegada == 10)
    {
        cout << "Lima -> San_Salvador -> San_Pedro_de_Sula " << endl;
        cout << "Lima -> San Jose de Costa Rica -> San_Pedro_de_Sula " << endl;
    }
    if (salida == 10 && llegada == 24)
    {
        cout << "San_Pedro_de_Sula -> San_Salvador -> Lima " << endl;
        cout << "San_Pedro_de_Sula -> San Jose de Costa Rica -> Lima " << endl;
    }
    if (salida == 24 && llegada == 12)
    {
        cout << "Lima -> San Jose de Costa Rica -> Tegucigalpa" << endl;
    }
    if (salida == 12 && llegada == 24)
    {
        cout << "Tegucigalpa -> San Jose de Costa Rica -> Lima " << endl;
    }
    if (salida == 24 && llegada == 13)
    {
        cout << "Lima -> Ciudad de Mexico -> San_Salvador" << endl;
        cout << "Lima -> Guayaquil -> San_Salvador" << endl;
    }
    if (salida == 13 && llegada == 24)
    {
        cout << "San_Salvador -> Ciudad de Mexico -> Lima " << endl;
        cout << "San_Salvador -> Guayaquil -> Lima " << endl;
    }
    if (salida == 24 && llegada == 14)
    {
        cout << "Lima -> San Salvador -> Managua" << endl;
        cout << "Lima -> Costa Rica -> Managua" << endl;
    }
    if (salida == 14 && llegada == 24)
    {
        cout << "Managua -> San Salvador -> Lima " << endl;
        cout << "Managua -> Costa Rica -> Lima " << endl;
    }
    if (salida == 24 && llegada == 15)
    {
        cout << "Lima -> San Salvador -> Liberia" << endl;
    }
    if (salida == 15 && llegada == 24)
    {
        cout << "Liberia -> San Salvador -> Lima " << endl;
    }
    if (salida == 24 && llegada == 16)
    {
        cout << "Lima -> Ciudad de Mexico -> San_Jose_de_Costa_Rica" << endl;
        cout << "Lima -> Santo Domingo -> San_Jose_de_Costa_Rica" << endl;
    }
    if (salida == 16 && llegada == 24)
    {
        cout << "San_Jose_de_Costa_Rica -> Ciudad de Mexico -> Lima " << endl;
        cout << "San_Jose_de_Costa_Rica -> Santo Domingo -> Lima " << endl;
    }
    if (salida == 24 && llegada == 17)
    {
        cout << "Lima -> San Salvador -> Ciudad_de_Panama" << endl;
        cout << "Lima -> San Jose de Costa Rica -> Ciudad_de_Panama" << endl;
    }
    if (salida == 17 && llegada == 24)
    {
        cout << "Ciudad_de_Panama -> San Salvador -> Lima " << endl;
        cout << "Ciudad_de_Panama -> San Jose de Costa Rica -> Lima " << endl;
    }
    if (salida == 24 && llegada == 18)
    {
        cout << "Lima -> San_Jose_de_Costa_Rica -> Caracas" << endl;
    }
    if (salida == 18 && llegada == 24)
    {
        cout << "Caracas -> San_Jose_de_Costa_Rica -> Lima " << endl;
    }
    if (salida == 24 && llegada == 19)
    {
        cout << "Lima -> San_Salvador -> Medellin " << endl;
        cout << "Lima -> San_Jose_de_Costa_Rica -> Medellin " << endl;
    }
    if (salida == 19 && llegada == 24)
    {
        cout << "Medellin -> San_Salvador -> Lima " << endl;
        cout << "Medellin -> San_Jose_de_Costa_Rica -> Lima " << endl;
    }
    if (salida == 24 && llegada == 20)
    {
        cout << "Lima -> San_Salvador -> Bogota" << endl;
        cout << "Lima -> Ciudad_de_Mexico -> Bogota" << endl;
    }
    if (salida == 20 && llegada == 24)
    {
        cout << "Bogota -> San_Salvador -> Lima " << endl;
        cout << "Bogota -> Ciudad_de_Mexico -> Lima " << endl;
    }
    if (salida == 24 && llegada == 21)
    {
        cout << "Lima -> San_Salvador -> Cali" << endl;
    }
    if (salida == 21 && llegada == 24)
    {
        cout << "Cali -> San_Salvador -> Lima " << endl;
    }
    if (salida == 24 && llegada == 22)
    {
        cout << "Lima -> San_Salvador -> Quito" << endl;
        cout << "Lima -> San_Jose_de_Costa_Rica -> Quito" << endl;
    }
    if (salida == 22 && llegada == 24)
    {
        cout << "Quito -> San_Salvador -> Lima " << endl;
        cout << "Quito -> San_Jose_de_Costa_Rica -> Lima " << endl;
    }
    if (salida == 24 && llegada == 23)
    {
        cout << "Lima -> San_Salvador -> Guayaquil" << endl;
    }
    if (salida == 23 && llegada == 24)
    {
        cout << "Guayaquil -> San_Salvador -> Lima " << endl;
    }

}
//VUELOS CON DOS ESCALAS VALIDACION Internacional y solo internacional
void internacional_nombre_con_dos_Escalas(int salida, int llegada)
{
    if (salida == 24 && llegada == 0)
    {
        cout << "Lima -> Guayaquil -> San_Salvador -> Ciudad_de_Mexico " << endl;
        cout << "Lima -> Quito -> San_Jose_de_Costa_Rica -> Ciudad_de_Mexico " << endl;
    }
    if (salida == 0 && llegada == 24)
    {
        cout << "Ciudad_de_Mexico -> San_Salvador -> Guayaquil -> Lima " << endl;
        cout << "Ciudad_de_Mexico -> San_Jose_de_Costa_Rica -> Quito -> Lima " << endl;
    }
    if (salida == 24 && llegada == 1)
    {
        cout << "Lima -> Ciudad_de_Mexico -> San_Salvador -> La_Habana" << endl;
    }
    if (salida == 1 && llegada == 24)
    {
        cout << "La_Habana -> San_Salvador -> Ciudad_de_Mexico -> Lima " << endl;
    }
    if (salida == 24 && llegada == 2)
    {
        cout << "Lima -> Ciudad_de_Mexico -> San_Salvador -> Cancun" << endl;
    }
    if (salida == 2 && llegada == 24)
    {
        cout << "Cancun -> San_Salvador -> Ciudad_de_Mexico -> Lima " << endl;
    }
    if (salida == 24 && llegada == 3)
    {
        cout << "Lima -> Ciudad_de_Mexico -> San_Salvador -> Belice " << endl;
    }
    if (salida == 3 && llegada == 24)
    {
        cout << "Belice -> San_Salvador -> Ciudad_de_Mexico -> Lima " << endl;
    }
    if (salida == 24 && llegada == 4)
    {
        cout << "Lima -> Guayaquil -> San_Salvador -> Ciudad_de_Guatemela" << endl;
        cout << "Lima -> Quito -> San_Jose_de_Costa_Rica -> Ciudad_de_ Guatemela" << endl;
    }
    if (salida == 4 && llegada == 24)
    {
        cout << "Ciudad_de_Guatemela -> San_Salvador -> Guayaquil -> Lima " << endl;
        cout << "Ciudad_de_Guatemela -> San_Jose_de_Costa_Rica -> Quito -> Lima" << endl;
    }
    if (salida == 24 && llegada == 5)
    {
        cout << "Lima -> San_Salvador -> Ciudad_de_Guatemela -> Flores " << endl;
    }if (salida == 5 && llegada == 24)
    {
        cout << "Flores -> Ciudad_de_Guatemela -> San_Salvador -> Lima " << endl;
    }if (salida == 24 && llegada == 6)
    {
        cout << "Lima -> San_Jose_de_Costa_Rica -> Bogota -> Punta_Cana " << endl;
        cout << "Lima -> Ciudad_de_Mexico -> Bogota -> Punta_Cana" << endl;
    }if (salida == 6 && llegada == 24)
    {
        cout << "Punta_Cana -> Bogota -> San_Jose_de_Costa_Rica -> Lima " << endl;
        cout << "Punta_Cana -> Bogota -> Ciudad_de_Mexico -> Lima" << endl;
    }if (salida == 24 && llegada == 7)
    {
        cout << "Lima -> Quito -> San_Jose_de_Costa_Rica -> Santo_Domingo " << endl;
        cout << "Lima -> San_Jose_de_Costa_Rica -> Bogota -> Santo_Domingo" << endl;
    }if (salida == 7 && llegada == 24)
    {
        cout << "Santo_Domingo -> San_Jose_de_Costa_Rica -> Quito -> Lima " << endl;
        cout << "Santo_Domingo -> Bogota -> San_Jose_de_Costa_Rica -> Lima" << endl;
    }
    if (salida == 24 && llegada == 8)
    {
        cout << "Lima -> Ciudad de Mexico -> Bogota -> San_Juan" << endl;
        cout << "Lima ->  Punta Cana -> Bogota -> San_Juan " << endl;

    }
    if (salida == 8 && llegada == 24)
    {
        cout << "San_Juan ->  Bogota -> Ciudad de Mexico -> Lima " << endl;
        cout << "San_Juan -> Bogota -> Punta Cana -> Lima " << endl;;
    }

    if (salida == 9 && llegada == 24)
    {
        cout << "Lima -> Ciudad de Mexico -> San Salvador -> Roatan" << endl;
        cout << "Lima -> Guayaquil -> San Salvador -> Roatan " << endl;

    }
    if (salida == 24 && llegada == 9)
    {
        cout << "Roatan -> San Salvador -> Ciudad de Mexico -> Lima " << endl;
        cout << "Roatan -> San Salvador -> Guayaquil ->Lima " << endl;
    }

    if (salida == 24 && llegada == 10)
    {
        cout << "Lima -> Ciudad de Mexico -> San Jose de Costa Rica -> San_Pedro_de_Sula " << endl;
        cout << "Lima -> San Salvador -> Roatan -> San_Pedro_de_Sula " << endl;
    }
    if (salida == 10 && llegada == 24)
    {
        cout << "San_Pedro_de_Sula -> San Jose de Costa Rica -> Ciudad de Mexico -> Lima " << endl;
        cout << "San_Pedro_de_Sula -> Roatan -> San Salvador -> Lima " << endl;
    }

    if (salida == 24 && llegada == 11)
    {
        cout << "Lima -> San Jose de Costa Rica -> Tegucigalpa -> La_Ceiba " << endl;

    }
    if (salida == 11 && llegada == 24)
    {
        cout << "La_Ceiba -> Tegucigalpa -> San Jose de Costa Rica -> Lima " << endl;
    }

    if (salida == 24 && llegada == 12)
    {
        cout << "Lima -> Santo Domingo -> San Jose de Costa Rica -> Tegucigalpa" << endl;
        cout << "Lima -> San Jose de Costa Rica -> Ciudad de Guatemala -> Tegucigalpa" << endl;
    }
    if (salida == 12 && llegada == 24)
    {
        cout << "Tegucigalpa -> San Jose de Costa Rica -> Santo Domingo -> Lima " << endl;
        cout << "Tegucigalpa -> Ciudad de Guatemala -> San Jose de Costa Rica -> Lima" << endl;

    }

    if (salida == 24 && llegada == 13)
    {
        cout << "Lima -> Santo Domingo -> Bogota -> San_Salvador" << endl;
        cout << "Lima -> Quito -> Medellin -> San_Salvador" << endl;
    }
    if (salida == 13 && llegada == 24)
    {
        cout << "San_Salvador -> Bogota -> Santo Domingo -> Lima" << endl;
        cout << "San_Salvador -> Medellin -> Quito -> Lima" << endl;
    }

    if (salida == 24 && llegada == 14)
    {
        cout << "Lima -> Santo Domingo -> San Jose de Costa Rica -> Managua" << endl;
        cout << "Lima -> Guayaquil -> San Salvador -> Managua" << endl;

    }
    if (salida == 14 && llegada == 24)
    {
        cout << "Managua -> San Jose de Costa Rica -> Santo Domingo -> Lima" << endl;
        cout << "Managua -> San Salvador -> Guayaquil-> Lima" << endl;
    }

    if (salida == 24 && llegada == 15)
    {
        cout << "Lima -> Ciudad de Mexico -> San Salvador -> Liberia" << endl;
        cout << "Lima -> San Jose de Costa Rica -> San Salvador -> Liberia" << endl;

    }
    if (salida == 15 && llegada == 24)
    {
        cout << "Liberia -> San Salvador -> Ciudad de Mexico -> Lima" << endl;
        cout << "Liberia -> San Salvador -> San Jose de Costa Rica -> Lima" << endl;

    }
    if (salida == 24 && llegada == 16)
    {
        cout << "Lima -> Quito -> Medellin -> San_Jose_de_Costa_Rica " << endl;
        cout << "Lima -> Ciudad_de_Mexico -> San_Salvador -> San_Jose_de_Costa_Rica " << endl;
    }
    if (salida == 16 && llegada == 24)
    {
        cout << "San_Jose_de_Costa_Rica -> Medellin -> Quito -> Lima " << endl;
        cout << "San_Jose_de_Costa_Rica -> San_Salvador -> Ciudad_de_Mexico -> Lima " << endl;
    }

    if (salida == 24 && llegada == 17)
    {
        cout << "Lima -> Quito -> San_Jose_de_Costa_Rica -> Ciudad_de_Panama " << endl;
        cout << "Lima -> Guayaquil -> San_Jose_de_Costa_Rica -> Ciudad_de_Panama " << endl;
    }
    if (salida == 17 && llegada == 24)
    {
        cout << "Ciudad_de_Panama -> San_Jose_de_Costa_Rica -> Quito -> Lima " << endl;
        cout << "Ciudad_de_Panama -> San_Jose_de_Costa_Rica -> Guayaquil -> Lima " << endl;
    }

    if (salida == 24 && llegada == 18)
    {
        cout << "Lima -> Quito -> San_Jose_de_Costa_Rica -> Caracas " << endl;
        cout << "Lima -> Guayaquil -> San_Jose_de_Costa_Rica -> Caracas " << endl;
    }
    if (salida == 18 && llegada == 24)
    {
        cout << "Caracas -> San_Jose_de_Costa_Rica -> Quito -> Lima " << endl;
        cout << "Caracas -> San_Jose_de_Costa_Rica -> Guayaquil -> Lima " << endl;
    }

    if (salida == 24 && llegada == 19)
    {
        cout << "Lima -> Ciudad_de_Mexico -> San_Jose_de_Costa_Rica -> Medellin " << endl;
        cout << "Lima -> Quito -> San_Jose_de_Costa_Rica -> Medellin " << endl;
    }
    if (salida == 19 && llegada == 24)
    {
        cout << "Medellin -> San_Jose_de_Costa_Rica -> Ciudad_de_Mexico -> Lima " << endl;
        cout << "Medellin -> San_Jose_de_Costa_Rica -> Quito -> Lima " << endl;
    }

    if (salida == 24 && llegada == 20)
    {
        cout << "Lima -> San_Jose_de_Costa_Rica -> Ciudad_de_Panama -> Bogota " << endl;
        cout << "Lima -> San_Jose_de_Costa_Rica -> Ciudad_de_Guatemala -> Bogota " << endl;
    }
    if (salida == 20 && llegada == 24)
    {
        cout << "Bogota -> Ciudad_de_Panama -> San_Jose_de_Costa_Rica -> Lima " << endl;
        cout << "Bogota -> Ciudad_de_Guatemala -> San_Jose_de_Costa_Rica -> Lima " << endl;
    }

    if (salida == 24 && llegada == 21)
    {
        cout << "Lima -> Guayaquil -> San_Salvador -> Cali " << endl;
        cout << "Lima -> Ciudad_de_Mexico -> San_Salvador -> Cali " << endl;
    }
    if (salida == 21 && llegada == 24)
    {
        cout << "Cali -> San_Salvador -> Guayaquil -> Lima " << endl;
        cout << "Cali -> San_Salvador -> Ciudad_de_Mexico -> Lima " << endl;
    }

    if (salida == 24 && llegada == 22)
    {
        cout << "Lima -> Guayaquil -> San_Salvador -> Quito " << endl;
        cout << "Lima -> San_Jose_de_Costa_Rica -> Medellin -> Quito " << endl;
    }
    if (salida == 22 && llegada == 24)
    {
        cout << "Quito -> San_Salvador -> Guayaquil -> Lima " << endl;
        cout << "Quito -> Medellin -> San_Jose_de_Costa_Rica -> Lima " << endl;
    }

    if (salida == 24 && llegada == 23)
    {
        cout << "Lima -> Quito -> San_Salvador -> Guayaquil " << endl;
        cout << "Lima -> Ciudad_de_Mexico -> San_Salvador -> Guayaquil " << endl;

    }
    if (salida == 23 && llegada == 24)
    {
        cout << "Guayaquil -> San_Salvador -> Quito -> Lima " << endl;
        cout << "Guayaquil -> San_Salvador -> Ciudad_de_Mexico -> Lima " << endl;

    }

}

void matriz_validad_internacional(int filabuscada_internacional, int columnabuscada_internacional, bool matriznatural[25][25], bool matriz_1_escala[25][25], bool matriz_2_escalas[25][25], string llegada)
{
    if ((filabuscada_internacional == -1 || columnabuscada_internacional == -1 || filabuscada_internacional > 24 || columnabuscada_internacional > 24 || (filabuscada_internacional < 25 && columnabuscada_internacional == -1) || (filabuscada_internacional == -1 && columnabuscada_internacional < 25)))
    {
        cout << "No existe vuelo disponible a " << llegada << endl;
    }
    else
    {
        if (matriznatural[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "* Existe vuelo directo a " << llegada << endl;
        }
        if (matriz_1_escala[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "* Existe vuelo con 1 escala a " << llegada << endl;
            internacional_nombre_con_una_Escala(filabuscada_internacional, columnabuscada_internacional);
        }
        if (matriz_2_escalas[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "* Existe vuelo con 2 escalas a " << llegada << endl;
            internacional_nombre_con_dos_Escalas(filabuscada_internacional, columnabuscada_internacional);
        }
    }
}

void matriz_validad_internacional_anacional(int filabuscada_internacional, int columnabuscada_internacional, bool matriznatural[25][25], bool matriz_1_escala[25][25], bool matriz_2_escalas[25][25])
{
    if ((filabuscada_internacional == -1 || columnabuscada_internacional == -1 || filabuscada_internacional > 24 || columnabuscada_internacional > 24 || (filabuscada_internacional < 25 && columnabuscada_internacional == -1) || (filabuscada_internacional == -1 && columnabuscada_internacional < 25)))
    {
        cout << "No existe vuelo disponible a lima" << endl;
    }
    else
    {
        if (matriznatural[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "* Existe vuelo directo a lima" << endl;
        }
        if (matriz_1_escala[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "* Existe vuelo con 1 escala a lima" << endl;
            internacional_nombre_con_una_Escala(filabuscada_internacional, columnabuscada_internacional);
        }
        if (matriz_2_escalas[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "* Existe vuelo con 2 escalas a lima" << endl;
            internacional_nombre_con_dos_Escalas(filabuscada_internacional, columnabuscada_internacional);
        }
    }
}

void matriz_validad_lima_aInternacional(int filabuscada_internacional, int columnabuscada_internacional, bool matriznatural[25][25], bool matriz_1_escala[25][25], bool matriz_2_escalas[25][25], string llegada)
{
    if ((filabuscada_internacional == -1 || columnabuscada_internacional == -1 || filabuscada_internacional > 24 || columnabuscada_internacional > 24 || (filabuscada_internacional < 25 && columnabuscada_internacional == -1) || (filabuscada_internacional == -1 && columnabuscada_internacional < 25)))
    {
        cout << "No existe vuelo disponible a " << llegada << endl;
    }
    else
    {
        if (matriznatural[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "* Existe vuelo directo a " << llegada << endl;
        }
        if (matriz_1_escala[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "* Existe vuelo con 1 escala a " << llegada << endl;
            internacional_nombre_con_una_Escala(filabuscada_internacional, columnabuscada_internacional);
        }
        if (matriz_2_escalas[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "* Existe vuelo con 2 escalas a " << llegada << endl;
            internacional_nombre_con_dos_Escalas(filabuscada_internacional, columnabuscada_internacional);
        }
    }
}

//funciones para colombia 
bool multiplicar_matrices_colombia(bool matriz[25][25], bool matriz2[25][25], bool resultado[25][25])
{
    //inicializamos la matriz resultado
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            resultado[i][j] = false;
        }
    }
    //multiplicamos las matrices
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            for (int k = 0; k < 25; k++)
            {
                resultado[i][j] = resultado[i][j] || (matriz[i][k] && matriz2[k][j]);
            }
        }
    }
    return true;
}

void valida_vuelos_colombianos(string a, string b)
{
    //filas
    {
        if (a == "San_Andres" || a == "SAN_ANDRES" || a == "san_andres")
        {
            filabuscada_colombia = 0;
        }
        if (a == "Cartagena" || a == "CARTAGENA" || a == "cartagena")
        {
            filabuscada_colombia = 1;
        }
        if (a == "Barranquilla" || a == "BARRANQUILLA" || a == "barranquilla")
        {
            filabuscada_colombia = 2;
        }
        if (a == "Santa_Marta" || a == "SANTA_MARTA" || a == "santa_marta")
        {
            filabuscada_colombia = 3;
        }
        if (a == "Riohacha" || a == "RIOHACHA" || a == "riohacha")
        {
            filabuscada_colombia = 4;
        }
        if (a == "Monteria" || a == "MONTERIA" || a == "monteria")
        {
            filabuscada_colombia = 5;
        }
        if (a == "Valledupar" || a == "VALLEDUPAR" || a == "valledupar")
        {
            filabuscada_colombia = 6;
        }
        if (a == "Medellin" || a == "MEDELLIN" || a == "medellin")
        {
            filabuscada_colombia = 7;
        }

        if (a == "Barrancabermeja" || a == "BARRANCABERMEJA" || a == "barrancabermeja")
        {
            filabuscada_colombia = 8;
        }
        if (a == "Bucaramanga" || a == "BUCARAMANGA" || a == "bucaramanga")
        {
            filabuscada_colombia = 9;
        }
        if (a == "Cucuta" || a == "CUCUTA" || a == "cucuta")
        {
            filabuscada_colombia = 10;
        }
        if (a == "Armenia" || a == "ARMENIA" || a == "armenia")
        {
            filabuscada_colombia = 11;
        }
        if (a == "Pereira" || a == "PEREIRA" || a == "pereira")
        {
            filabuscada_colombia = 12;
        }
        if (a == "Manizales" || a == "MANIZALES" || a == "manizales")
        {
            filabuscada_colombia = 13;
        }
        if (a == "Yopal" || a == "YOPAL" || a == "yopal")
        {
            filabuscada_colombia = 14;
        }
        if (a == "Ibague" || a == "IBAGUE" || a == "ibague")
        {
            filabuscada_colombia = 15;
        }
        if (a == "Bogota" || a == "bogota" || a == "BOGOTA")
        {
            filabuscada_colombia = 16;
        }
        if (a == "Tumaco" || a == "tumaco" || a == "TUMACO")
        {
            filabuscada_colombia = 17;
        }
        if (a == "Cali" || a == "cali" || a == "CALI")
        {
            filabuscada_colombia = 18;
        }
        if (a == "Pasto" || a == "pasto" || a == "PASTO")
        {
            filabuscada_colombia = 19;
        }
        if (a == "Popayan" || a == "popayan" || a == "POPAYAN")
        {
            filabuscada_colombia = 20;
        }
        if (a == "Neiva" || a == "neiva" || a == "NEIVA")
        {
            filabuscada_colombia = 21;
        }
        if (a == "Villavicencio" || a == "villavicencio" || a == "VILLAVICENCIO")
        {
            filabuscada_colombia = 22;
        }
        if (a == "Leticia" || a == "leticia" || a == "LETICIA")
        {
            filabuscada_colombia = 23;
        }
        if (a == "Florencia" || a == "florencia" || a == "FLORENCIA")
        {
            filabuscada_colombia = 24;
        }
    }

    //columnas    
    {
        if (b == "San_Andres" || b == "SAN_ANDRES" || b == "san_andres")
        {
            columnabuscada_colombia = 0;
        }
        if (b == "Cartagena" || b == "CARTAGENA" || b == "cartagena")
        {
            columnabuscada_colombia = 1;
        }
        if (b == "Barranquilla" || b == "BARRANQUILLA" || b == "barranquilla")
        {
            columnabuscada_colombia = 2;
        }
        if (b == "Santa_Marta" || b == "SANTA_MARTA" || b == "santa_marta")
        {
            columnabuscada_colombia = 3;
        }
        if (b == "Riohacha" || b == "RIOHACHA" || b == "riohacha")
        {
            columnabuscada_colombia = 4;
        }
        if (b == "Monteria" || b == "MONTERIA" || b == "monteria")
        {
            columnabuscada_colombia = 5;
        }
        if (b == "Valledupar" || b == "VALLEDUPAR" || b == "valledupar")
        {
            columnabuscada_colombia = 6;
        }
        if (b == "Medellin" || b == "MEDELLIN" || b == "medellin")
        {
            columnabuscada_colombia = 7;
        }
        if (b == "Barrancabermeja" || b == "BARRANCABERMEJA" || b == "barrancabermeja")
        {
            columnabuscada_colombia = 8;
        }
        if (b == "Bucaramanga" || b == "BUCARAMANGA" || b == "bucaramanga")
        {
            columnabuscada_colombia = 9;
        }
        if (b == "Cucuta" || b == "CUCUTA" || b == "cucuta")
        {
            columnabuscada_colombia = 10;
        }
        if (b == "Armenia" || b == "ARMENIA" || b == "armenia")
        {
            columnabuscada_colombia = 11;
        }
        if (b == "Pereira" || b == "PEREIRA" || b == "pereira")
        {
            columnabuscada_colombia = 12;
        }
        if (b == "Manizales" || b == "MANIZALES" || b == "manizales")
        {
            columnabuscada_colombia = 13;
        }
        if (b == "Yopal" || b == "YOPAL" || b == "yopal")
        {
            columnabuscada_colombia = 14;
        }
        if (b == "Ibague" || b == "IBAGUE" || b == "ibague")
        {
            columnabuscada_colombia = 15;
        }
        if (b == "Bogota" || b == "bogota" || b == "BOGOTA")
        {
            columnabuscada_colombia = 16;
        }
        if (b == "Tumaco" || b == "tumaco" || b == "TUMACO")
        {
            columnabuscada_colombia = 17;
        }
        if (b == "Cali" || b == "cali" || b == "CALI")
        {
            columnabuscada_colombia = 18;
        }
        if (b == "Pasto" || b == "pasto" || b == "PASTO")
        {
            columnabuscada_colombia = 19;
        }
        if (b == "Popayan" || b == "popayan" || b == "POPAYAN")
        {
            columnabuscada_colombia = 20;
        }
        if (b == "Neiva" || b == "neiva" || b == "NEIVA")
        {
            columnabuscada_colombia = 21;
        }
        if (b == "Villavicencio" || b == "villavicencio" || b == "VILLAVICENCIO")
        {
            columnabuscada_colombia = 22;
        }
        if (b == "Leticia" || b == "leticia" || b == "LETICIA")
        {
            columnabuscada_colombia = 23;
        }
        if (b == "Florencia" || b == "florencia" || b == "FLORENCIA")
        {
            columnabuscada_colombia = 24;
        }
    }


}
// VUELOS CON UNA ESCALA VALIDACION Colombia y solo Colombia 
void colombia_nombre_con_una_escala(int salida, int llegada)
{
    if (salida == 7 && llegada == 0)
    {
        cout << "Medellin -> Bogota -> San_Andres " << endl;
    }
    if (salida == 0 && llegada == 7)
    {
        cout << "San_Andres -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 1)
    {
        cout << "Medellin -> Bogota -> Cartagena" << endl;
        cout << "Medellin -> Cali -> Cartagena" << endl;
    }
    if (salida == 1 && llegada == 7)
    {
        cout << "Cartagena -> Bogota -> Medellin " << endl;
        cout << "Cartagena -> Cali -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 2)
    {
        cout << "Medellin -> Bogota -> Barranquilla" << endl;
        cout << "Medellin -> Cali -> Barranquilla" << endl;
    }
    if (salida == 2 && llegada == 7)
    {
        cout << "Barranquilla -> Bogota -> Medellin " << endl;
        cout << "Barranquilla -> Cali -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 3)
    {
        cout << "Medellin -> Bogota -> Santa_Marta " << endl;
    }
    if (salida == 3 && llegada == 7)
    {
        cout << "Santa_Marta -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 4)
    {
        cout << "Medellin -> Bogota -> Riohacha" << endl;
    }
    if (salida == 4 && llegada == 7)
    {
        cout << "Riohacha -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 5)
    {
        cout << "Medellin -> Bogota -> Monteria" << endl;
    }
    if (salida == 5 && llegada == 7)
    {
        cout << "Monteria -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 6)
    {
        cout << "Medellin -> Bogota -> Valledupar " << endl;
    }
    if (salida == 6 && llegada == 7)
    {
        cout << "Valledupar -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 8)
    {
        cout << "Medellin -> Bogota -> Barrancabemeja " << endl;
    }
    if (salida == 8 && llegada == 7)
    {
        cout << "Barrancabemeja -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 9)
    {
        cout << "Medellin -> Bogota -> Bucaramanga" << endl;
    }
    if (salida == 9 && llegada == 7)
    {
        cout << "Bucaramanga -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 10)
    {
        cout << "Medellin -> Bogota -> Cucuta" << endl;
    }
    if (salida == 10 && llegada == 7)
    {
        cout << "Cucuta -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 11)
    {
        cout << "Medellin -> Bogota -> Armenia " << endl;
    }
    if (salida == 11 && llegada == 7)
    {
        cout << "Armenia -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 12)
    {
        cout << "Medellin -> Bogota -> Pereira" << endl;
    }
    if (salida == 12 && llegada == 7)
    {
        cout << "Pereira -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 13)
    {
        cout << "Medellin -> Bogota -> Manizales" << endl;
    }
    if (salida == 13 && llegada == 7)
    {
        cout << "Manizales -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 14)
    {
        cout << "Medellin -> Bogota -> Yopal " << endl;
    }
    if (salida == 14 && llegada == 7)
    {
        cout << "Yopal -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 15)
    {
        cout << "Medellin -> Bogota -> Ibague " << endl;
    }
    if (salida == 15 && llegada == 7)
    {
        cout << "Ibague -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 16)
    {
        cout << "Medellin -> Bucaramanga -> Bogota " << endl;
        cout << "Medellin -> Cucuta -> Bogota " << endl;
    }
    if (salida == 16 && llegada == 7)
    {
        cout << "Bogota -> Bucaramanga -> Medellin " << endl;
        cout << "Bogota -> Cucuta -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 17)
    {
        cout << "Medellin -> Cali -> Tumaco" << endl;
    }
    if (salida == 17 && llegada == 7)
    {
        cout << "Tumaco -> Cali -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 18)
    {
        cout << "Medellin -> Bogota -> Cali" << endl;
    }
    if (salida == 18 && llegada == 7)
    {
        cout << "Cali -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 19)
    {
        cout << "Medellin -> Cali -> Pasto " << endl;
        cout << "Medellin -> Bogota -> Pasto " << endl;
    }
    if (salida == 19 && llegada == 7)
    {
        cout << "Pasto -> Cali -> Medellin " << endl;
        cout << "Pasto -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 20)
    {
        cout << "Medellin -> Bogota -> Popoyan" << endl;
    }
    if (salida == 20 && llegada == 7)
    {
        cout << "Popoyan -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 21)
    {
        cout << "Medellin -> Bogota -> Neiva" << endl;
    }
    if (salida == 21 && llegada == 7)
    {
        cout << "Neiva -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 22)
    {
        cout << "Medellin -> Bogota -> Villavicencio " << endl;
    }
    if (salida == 22 && llegada == 7)
    {
        cout << "Villavicencio -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 23)
    {
        cout << "Medellin -> Bogota -> Leticia " << endl;
    }
    if (salida == 23 && llegada == 7)
    {
        cout << "Leticia -> Bogota -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 24)
    {
        cout << "Medellin -> Bogota -> Florencia" << endl;
    }
    if (salida == 24 && llegada == 7)
    {
        cout << "Florencia -> Bogota -> Medellin " << endl;
    }
    if (salida == 18 && llegada == 0)
    {
        cout << "Cali -> Bogota -> San Andres " << endl;

    }
    if (salida == 0 && llegada == 18)
    {
        cout << "San Andres -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 1)
    {
        cout << "Cali -> Bogota -> Cartagena" << endl;
        cout << "Cali -> Medellin -> Cartagena" << endl;
    }
    if (salida == 1 && llegada == 18)
    {
        cout << "Cartagena -> Bogota -> Cali " << endl;
        cout << "Cartagena -> Medellin -> Cali" << endl;
    }
    if (salida == 18 && llegada == 2)
    {
        cout << "Cali -> Bogota -> Barranquilla" << endl;
        cout << "Cali -> Medellin -> Barranquilla" << endl;
    }
    if (salida == 2 && llegada == 18)
    {
        cout << "Barranquilla -> Bogota -> Cali " << endl;
        cout << "Barranquilla -> Medellin -> Cali " << endl;
    }
    if (salida == 18 && llegada == 3)
    {
        cout << "Cali -> Bogota -> Santa Marta" << endl;
        cout << "Cali -> Medellin -> Santa Marta" << endl;
    }
    if (salida == 3 && llegada == 18)
    {
        cout << "Santa Marta -> Bogota -> Cali " << endl;
        cout << "Santa Marta -> Medellin -> Cali " << endl;
    }
    if (salida == 18 && llegada == 4)
    {
        cout << "Cali -> Bogota -> Riohacha" << endl;
    }
    if (salida == 4 && llegada == 18)
    {
        cout << "Riohacha -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 5)
    {
        cout << "Cali -> Bogota -> Monteria" << endl;
    }
    if (salida == 5 && llegada == 18)
    {
        cout << "Monteria -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 6)
    {
        cout << "Cali -> Bogota -> Valledupar" << endl;
    }
    if (salida == 6 && llegada == 18)
    {
        cout << "Valledupar -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 7)
    {
        cout << "Cali -> Cartagena -> Medellin" << endl;
        cout << "Cali -> Barranquilla -> Medellin" << endl;
    }
    if (salida == 7 && llegada == 18)
    {
        cout << "Medellin -> Cartagena -> Cali " << endl;
        cout << "Medellin -> Barranquilla -> Cali " << endl;
    }
    if (salida == 18 && llegada == 8)
    {
        cout << "Cali -> Bogota -> Barrancabermeja" << endl;
    }
    if (salida == 8 && llegada == 18)
    {
        cout << "Barrancabermeja -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 9)
    {
        cout << "Cali -> Bogota -> Bucaramanga" << endl;
        cout << "Cali -> Medellin -> Bucaramanga" << endl;
    }
    if (salida == 9 && llegada == 18)
    {
        cout << "Bucaramanga -> Bogota -> Cali " << endl;
        cout << "Bucaramanga -> Medellin -> Cali " << endl;
    }
    if (salida == 18 && llegada == 10)
    {
        cout << "Cali -> Bogota -> Cucuta" << endl;
        cout << "Cali -> Medellin -> Cucuta" << endl;
    }
    if (salida == 10 && llegada == 18)
    {
        cout << "Cucuta -> Bogota -> Cali " << endl;
        cout << "Cucuta -> Medellin -> Cali " << endl;
    }
    if (salida == 18 && llegada == 11)
    {
        cout << "Cali -> Bogota -> Armenia" << endl;

    }
    if (salida == 11 && llegada == 18)
    {
        cout << "Armenia -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 12)
    {
        cout << "Cali -> Bogota -> Pereira" << endl;

    }
    if (salida == 12 && llegada == 18)
    {
        cout << "Pereira -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 13)
    {
        cout << "Cali -> Bogota -> Manizales" << endl;

    }
    if (salida == 13 && llegada == 18)
    {
        cout << "Manizales -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 14)
    {
        cout << "Cali -> Bogota -> Yopal" << endl;

    }
    if (salida == 14 && llegada == 18)
    {
        cout << "Yopal -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 15)
    {
        cout << "Cali -> Bogota -> Ibague" << endl;

    }
    if (salida == 15 && llegada == 18)
    {
        cout << "Ibague -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 16)
    {
        cout << "Cali -> Cartagena -> Bogota" << endl;
        cout << "Cali -> Barranquilla -> Bogota" << endl;
    }
    if (salida == 16 && llegada == 18)
    {
        cout << "Bogota -> Cartagena -> Cali " << endl;
        cout << "Bogota -> Barranquilla -> Cali " << endl;
    }
    if (salida == 18 && llegada == 19)
    {
        cout << "Cali -> Bogota -> Pasto" << endl;
    }
    if (salida == 19 && llegada == 18)
    {
        cout << "Pasto -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 20)
    {
        cout << "Cali -> Bogota -> Popayan" << endl;
    }
    if (salida == 20 && llegada == 18)
    {
        cout << "Popayan -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 21)
    {
        cout << "Cali -> Bogota -> Neiva" << endl;
    }
    if (salida == 21 && llegada == 18)
    {
        cout << "Neiva -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 22)
    {
        cout << "Cali -> Bogota -> Villavicencio" << endl;
    }
    if (salida == 22 && llegada == 18)
    {
        cout << "Villavicencio -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 23)
    {
        cout << "Cali -> Bogota -> Leticia" << endl;
    }
    if (salida == 23 && llegada == 18)
    {
        cout << "Leticia -> Bogota -> Cali " << endl;
    }
    if (salida == 18 && llegada == 24)
    {
        cout << "Cali -> Bogota -> Florencia" << endl;
    }
    if (salida == 24 && llegada == 18)
    {
        cout << "Florencia -> Bogota -> Cali " << endl;
    }
    if (salida == 16 && llegada == 1)
    {
        cout << "Bogota -> Cali -> Cartagena" << endl;
        cout << "Bogota -> Medellin -> Cartagena" << endl;
    }
    if (salida == 1 && llegada == 16)
    {
        cout << "Cartagena -> Cali -> Bogota " << endl;
        cout << "Cartagena -> Medellin -> Bogota " << endl;
    }
    if (salida == 16 && llegada == 2)
    {
        cout << "Bogota -> Medellin -> Barranquilla " << endl;
        cout << "Bogota -> Cali -> Barranquilla " << endl;
    }
    if (salida == 2 && llegada == 16)
    {
        cout << "Barranquilla -> Medellin -> Bogota " << endl;
        cout << "Barranquilla -> Cali -> Bogota " << endl;
    }
    if (salida == 16 && llegada == 3)
    {
        cout << "Bogota -> Medellin -> Santa_Marta" << endl;
    }
    if (salida == 3 && llegada == 16)
    {
        cout << "Santa_Marta -> Medellin -> Bogota " << endl;
    }
    if (salida == 16 && llegada == 7)
    {
        cout << "Bogota -> Cucuta -> Medellin" << endl;
        cout << "Bogota -> Bucaramanga -> Medellin" << endl;
    }
    if (salida == 7 && llegada == 16)
    {
        cout << "Medellin -> Cucuta -> Bogota " << endl;
        cout << "Medellin -> Bucaramanga -> Bogota " << endl;
    }
    if (salida == 16 && llegada == 9)
    {
        cout << "Bogota -> Medellin -> Bucaramanga" << endl;
    }
    if (salida == 9 && llegada == 16)
    {
        cout << "Bucaramanga -> Medellin -> Bogota " << endl;
    }
    if (salida == 16 && llegada == 10)
    {
        cout << "Bogota -> Medellin -> Cucuta" << endl;
    }
    if (salida == 10 && llegada == 16)
    {
        cout << "Cucuta -> Medellin -> Bogota " << endl;
    }
    if (salida == 16 && llegada == 17)
    {
        cout << "Bogota -> Cali -> Tumaco" << endl;
    }
    if (salida == 17 && llegada == 16)
    {
        cout << "Tumaco -> Cali -> Bogota " << endl;
    }
    if (salida == 16 && llegada == 18)
    {
        cout << "Bogota -> Medellin -> Cali" << endl;
        cout << "Bogota -> Cartagena -> Cali" << endl;
    }
    if (salida == 18 && llegada == 16)
    {
        cout << "Cali -> Medellin -> Bogota " << endl;
        cout << "Cali -> Cartagena -> Bogota " << endl;
    }
    if (salida == 16 && llegada == 19)
    {
        cout << "Bogota -> Cali -> Pasto" << endl;
    }
    if (salida == 19 && llegada == 16)
    {
        cout << "Pasto -> Cali -> Bogota " << endl;
    }


}
void colombian_nombre_con_dos_escalas(int salida, int llegada)
{
    if (salida == 7 && llegada == 0)
    {
        cout << "Medellin -> Cali -> Bogota -> San_Andres " << endl;
        cout << "Medellin -> Cucuta -> Bogota -> San_Andres " << endl;
    }
    if (salida == 0 && llegada == 7)
    {
        cout << "San_Andres -> Bogota -> Cali -> Medellin " << endl;
        cout << "San_Andres -> Bogota -> Cucuta -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 1)
    {
        cout << "Medellin -> Bogota -> Cali -> Cartagena" << endl;
        cout << "Medellin -> Bucaramanga -> Bogota -> Cartagena" << endl;
    }
    if (salida == 1 && llegada == 7)
    {
        cout << "Cartagena -> Cali -> Bogota -> Medellin " << endl;
        cout << "Cartagena -> Bogota -> Bucaramanga -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 2)
    {
        cout << "Medellin -> Bogota -> Cali -> Barranquilla" << endl;
        cout << "Medellin -> Cucuta -> Bogota -> Barranquilla" << endl;
    }
    if (salida == 2 && llegada == 7)
    {
        cout << "Barranquilla -> Cali -> Bogota -> Medellin " << endl;
        cout << "Barranquilla -> Bogota -> Cucuta -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 3)
    {
        cout << "Medellin -> Cali -> Bogota -> Santa_Marta " << endl;
        cout << "Medellin -> Bucaramanga -> Bogota -> Santa_Marta " << endl;
    }
    if (salida == 3 && llegada == 7)
    {
        cout << "Santa_Marta -> Bogota -> Cali -> Medellin " << endl;
        cout << "Santa_Marta -> Bogota -> Bucaramanga -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 4)
    {
        cout << "Medellin -> Cali -> Bogota -> Riohacha" << endl;
        cout << "Medellin -> Cucuta -> Bogota -> Riohacha" << endl;
    }
    if (salida == 4 && llegada == 7)
    {
        cout << "Riohacha -> Bogota -> Cali -> Medellin " << endl;
        cout << "Riohacha -> Bogota -> Cucuta -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 5)
    {
        cout << "Medellin -> Cali -> Bogota -> Monteria" << endl;
        cout << "Medellin -> Bucaramanga -> Bogota -> Monteria" << endl;
    }
    if (salida == 5 && llegada == 7)
    {
        cout << "Monteria -> Bogota -> Cali -> Medellin " << endl;
        cout << "Monteria -> Bogota -> Bucaramanga -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 6)
    {
        cout << "Medellin -> Cali -> Bogota -> Valledupar " << endl;
        cout << "Medellin -> Cucuta -> Bogota -> Valledupar " << endl;
    }
    if (salida == 6 && llegada == 7)
    {
        cout << "Valledupar -> Bogota -> Cali -> Medellin " << endl;
        cout << "Valledupar -> Bogota -> Cucuta -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 8)
    {
        cout << "Medellin -> Cali -> Bogota -> Barrancabemeja " << endl;
        cout << "Medellin -> Bucaramanga -> Bogota -> Barrancabemeja " << endl;
    }
    if (salida == 8 && llegada == 7)
    {
        cout << "Barrancabemeja -> Bogota -> Cali -> Medellin " << endl;
        cout << "Barrancabemeja -> Bogota -> Bucaramanga -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 9)
    {
        cout << "Medellin -> Cali -> Bogota -> Bucaramanga" << endl;
        cout << "Medellin -> Cucuta -> Bogota -> Bucaramanga" << endl;
    }
    if (salida == 9 && llegada == 7)
    {
        cout << "Bucaramanga -> Bogota -> Cali -> Medellin " << endl;
        cout << "Bucaramanga -> Bogota -> Cucuta -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 10)
    {
        cout << "Medellin -> Cali -> Bogota -> Cucuta" << endl;
        cout << "Medellin -> Bucaramanga -> Bogota -> Cucuta" << endl;
    }
    if (salida == 10 && llegada == 7)
    {
        cout << "Cucuta -> Bogota -> Cali -> Medellin " << endl;
        cout << "Cucuta -> Bogota -> Bucaramanga -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 11)
    {
        cout << "Medellin -> Cali -> Bogota -> Armenia " << endl;
        cout << "Medellin -> Cucuta -> Bogota -> Armenia " << endl;
    }
    if (salida == 11 && llegada == 7)
    {
        cout << "Armenia -> Bogota -> Cali -> Medellin " << endl;
        cout << "Armenia -> Bogota -> Cucuta -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 12)
    {
        cout << "Medellin -> Cali -> Bogota -> Pereira" << endl;
        cout << "Medellin -> Cucuta -> Bogota -> Pereira" << endl;
    }
    if (salida == 12 && llegada == 7)
    {
        cout << "Pereira -> Bogota -> Cali -> Medellin " << endl;
        cout << "Pereira -> Bogota -> Cucuta -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 13)
    {
        cout << "Medellin -> Cali -> Bogota -> Manizales" << endl;
        cout << "Medellin -> Bucaramanga -> Bogota -> Manizales" << endl;
    }
    if (salida == 13 && llegada == 7)
    {
        cout << "Manizales -> Bogota -> Cali -> Medellin " << endl;
        cout << "Manizales -> Bogota -> Bucaramanga -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 14)
    {
        cout << "Medellin -> Cali -> Bogota -> Yopal " << endl;
        cout << "Medellin -> Cucuta -> Bogota -> Yopal " << endl;
    }
    if (salida == 14 && llegada == 7)
    {
        cout << "Yopal -> Bogota -> Cali -> Medellin " << endl;
        cout << "Yopal -> Bogota -> Cucuta -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 15)
    {
        cout << "Medellin -> Cali -> Bogota -> Ibague " << endl;
        cout << "Medellin -> Bucaramanga -> Bogota -> Ibague " << endl;
    }
    if (salida == 15 && llegada == 7)
    {
        cout << "Ibague -> Bogota -> Cali -> Medellin " << endl;
        cout << "Ibague -> Bogota -> Bucaramanga -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 16)
    {
        cout << "Medellin ->Cali -> Pasto -> Bogota " << endl;
        cout << "Medellin -> Cartagena -> Cali -> Bogota " << endl;
    }
    if (salida == 16 && llegada == 7)
    {
        cout << "Bogota -> Pasto -> Cali -> Medellin " << endl;
        cout << "Bogota -> Cali -> Cartagena -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 17)
    {
        cout << "Medellin -> Bogota -> Cali -> Tumaco" << endl;
        cout << "Medellin -> Cartagena -> Cali -> Tumaco" << endl;
    }
    if (salida == 17 && llegada == 7)
    {
        cout << "Tumaco -> Cali -> Bogota -> Medellin " << endl;
        cout << "Tumaco -> Cali -> Cartagena -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 18)
    {
        cout << "Medellin -> Cucuta -> Bogota -> Cali" << endl;
        cout << "Medellin -> Bucaramanga -> Bogota -> Cali" << endl;
    }
    if (salida == 18 && llegada == 7)
    {
        cout << "Cali -> Bogota -> Cucuta -> Medellin " << endl;
        cout << "Cali -> Bogota -> Bucarmanga -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 19)
    {
        cout << "Medellin -> Cali -> Bogota -> Pasto " << endl;
        cout << "Medellin -> Cucuta -> Bogota -> Pasto " << endl;
    }
    if (salida == 19 && llegada == 7)
    {
        cout << "Pasto -> Bogota -> Cali -> Medellin " << endl;
        cout << "Pasto -> Bogota -> Cucuta -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 20)
    {
        cout << "Medellin -> Cali -> Bogota -> Popoyan" << endl;
        cout << "Medellin -> Bucaramanga -> Bogota -> Popoyan" << endl;
    }
    if (salida == 20 && llegada == 7)
    {
        cout << "Popoyan -> Bogota -> Cali -> Medellin " << endl;
        cout << "Popoyan -> Bogota -> Bucarmanga -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 21)
    {
        cout << "Medellin -> Cali -> Bogota -> Neiva" << endl;
        cout << "Medellin -> Cucuta -> Bogota -> Neiva" << endl;
    }
    if (salida == 21 && llegada == 7)
    {
        cout << "Neiva -> Bogota -> Cali -> Medellin " << endl;
        cout << "Neiva -> Bogota -> Cucuta-> Medellin " << endl;
    }
    if (salida == 7 && llegada == 22)
    {
        cout << "Medellin -> Cali -> Bogota -> Villavicencio " << endl;
        cout << "Medellin -> Cucuta -> Bogota -> Villavicencio " << endl;
    }
    if (salida == 22 && llegada == 7)
    {
        cout << "Villavicencio -> Bogota -> Cali -> Medellin " << endl;
        cout << "Villavicencio -> Bogota -> Cucuta -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 23)
    {
        cout << "Medellin -> Cali -> Bogota -> Leticia " << endl;
        cout << "Medellin -> Bucaramanga -> Bogota -> Leticia " << endl;
    }
    if (salida == 23 && llegada == 7)
    {
        cout << "Leticia -> Bogota -> Cali -> Medellin " << endl;
        cout << "Leticia -> Bogota -> Bucaramanga -> Medellin " << endl;
    }
    if (salida == 7 && llegada == 24)
    {
        cout << "Medellin -> Cali -> Bogota -> Florencia" << endl;
        cout << "Medellin -> Cucuta -> Bogota -> Florencia" << endl;
    }
    if (salida == 24 && llegada == 7)
    {
        cout << "Florencia -> Bogota -> Cali -> Medellin " << endl;
        cout << "Florencia -> Bogota -> Cucuta -> Medellin " << endl;
    }
    if (salida == 16 && llegada == 0)
    {
        cout << "Bogota -> Villavicencio -> Bogota -> San Andres " << endl;
        cout << "Bogota -> Neiva -> Bogota -> San Andres " << endl;

    }
    if (salida == 0 && llegada == 16)
    {
        cout << "San Andres -> Bogota -> Villavicencio -> Bogota " << endl;
        cout << "San Andres -> Bogota -> Neiva -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 1)
    {
        cout << "Bogota -> Cali -> Medellin -> Cartagena " << endl;
        cout << "Bogota -> Pasto -> Cali -> Cartagena " << endl;

    }
    if (salida == 1 && llegada == 16)
    {
        cout << "Cartagena -> Medellin -> Cali -> Bogota " << endl;
        cout << "Cartagena -> Pasto -> Cali -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 2)
    {
        cout << "Bogota -> Cali -> Medellin -> Barranquilla " << endl;
        cout << "Bogota -> Cucuta -> Medellin -> Barranquilla " << endl;

    }
    if (salida == 2 && llegada == 16)
    {
        cout << "Barranquilla -> Medellin -> Cali -> Bogota " << endl;
        cout << "Barranquilla -> Medellin -> Cucuta -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 3)
    {
        cout << "Bogota -> Cali -> Medellin -> Santa_Marta " << endl;
        cout << "Bogota -> Cucuta -> Medellin -> Santa_Marta " << endl;

    }
    if (salida == 3 && llegada == 16)
    {
        cout << "Santa_Marta -> Medellin -> Cali -> Bogota " << endl;
        cout << "Santa_Marta -> Cucuta -> Medellin -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 4)
    {
        cout << "Bogota -> Yopal -> Bogota -> Riohacha " << endl;
        cout << "Bogota -> Villavicencio -> Bogota -> Riohacha " << endl;

    }
    if (salida == 4 && llegada == 16)
    {
        cout << "Riohacha -> Bogota -> Yopal -> Bogota " << endl;
        cout << "Riohacha -> Bogota -> Villavicencio -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 5)
    {
        cout << "Bogota -> Yopal -> Bogota -> Monteria " << endl;
        cout << "Bogota -> Villavicencio -> Bogota -> Monteria " << endl;

    }
    if (salida == 5 && llegada == 16)
    {
        cout << "Monteria -> Bogota -> Yopal -> Bogota " << endl;
        cout << "Monteria -> Bogota -> Villavicencio -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 6)
    {
        cout << "Bogota -> Yopal -> Bogota -> Valledupar " << endl;
        cout << "Bogota -> Villavicencio -> Bogota -> Valledupar " << endl;

    }
    if (salida == 6 && llegada == 16)
    {
        cout << "Valledupar -> Bogota -> Yopal -> Bogota " << endl;
        cout << "Valledupar -> Bogota -> Villavicencio -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 7)
    {
        cout << "Bogota -> Pasto -> Cali -> Medellin " << endl;
        cout << "Bogota -> Cartagena -> Cali -> Medellin " << endl;

    }
    if (salida == 7 && llegada == 16)
    {
        cout << "Medellin -> Cali -> Pasto -> Bogota " << endl;
        cout << "Medellin -> Cali -> Cartagena -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 8)
    {
        cout << "Bogota -> Yopal -> Bogota -> Barrancabermeja " << endl;
        cout << "Bogota -> Villavicencio -> Bogota -> Barrancabermeja " << endl;

    }
    if (salida == 8 && llegada == 16)
    {
        cout << "Barrancabermeja -> Bogota -> Yopal -> Bogota " << endl;
        cout << "Barrancabermeja -> Bogota -> Villavicencio -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 9)
    {
        cout << "Bogota -> Cali -> Medellin -> Bucaramanga " << endl;
        cout << "Bogota -> Barranquilla -> Medellin -> Bucaramanga " << endl;

    }
    if (salida == 9 && llegada == 16)
    {
        cout << "Bucaramanga -> Medellin -> Cali -> Bogota " << endl;
        cout << "Bucaramanga -> Medellin -> Barranquilla -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 10)
    {
        cout << "Bogota -> Cali -> Medellin -> Cucuta " << endl;
        cout << "Bogota -> Barranquilla -> Medellin -> Cucuta " << endl;

    }
    if (salida == 10 && llegada == 16)
    {
        cout << "Cucuta -> Medellin -> Cali -> Bogota " << endl;
        cout << "Cucuta -> Medellin -> Barranquilla -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 11)
    {
        cout << "Bogota -> Yopal -> Bogota -> Armenia " << endl;
        cout << "Bogota -> Villavicencio -> Bogota -> Armenia " << endl;

    }
    if (salida == 11 && llegada == 16)
    {
        cout << "Armenia -> Bogota -> Yopal -> Bogota " << endl;
        cout << "Armenia -> Bogota -> Villavicencio -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 12)
    {
        cout << "Bogota -> Yopal -> Bogota -> Pereira " << endl;
        cout << "Bogota -> Villavicencio -> Bogota -> Pereira " << endl;

    }
    if (salida == 12 && llegada == 16)
    {
        cout << "Pereira -> Bogota -> Yopal -> Bogota " << endl;
        cout << "Pereira -> Bogota -> Villavicencio -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 13)
    {
        cout << "Bogota -> Yopal -> Bogota -> Manizales " << endl;
        cout << "Bogota -> Villavicencio -> Bogota -> Manizales " << endl;

    }
    if (salida == 13 && llegada == 16)
    {
        cout << "Manizales -> Bogota -> Yopal -> Bogota " << endl;
        cout << "Manizales -> Bogota -> Villavicencio -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 14)
    {
        cout << "Bogota -> Manizales -> Bogota -> Yopal " << endl;
        cout << "Bogota -> Villavicencio -> Bogota -> Yopal " << endl;

    }
    if (salida == 14 && llegada == 16)
    {
        cout << "Yopal -> Bogota -> Manizales -> Bogota " << endl;
        cout << "Yopal -> Bogota -> Villavicencio -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 15)
    {
        cout << "Bogota -> Manizales -> Bogota ->  Ibague " << endl;
        cout << "Bogota -> Villavicencio -> Bogota -> Ibague " << endl;

    }
    if (salida == 15 && llegada == 16)
    {
        cout << "Ibague -> Bogota -> Manizales -> Bogota " << endl;
        cout << "Ibague -> Bogota -> Villavicencio -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 17)
    {
        cout << "Bogota -> Medellin -> Cali -> Tumaco " << endl;
        cout << "Bogota -> Pasto -> Cali -> Tumaco " << endl;

    }
    if (salida == 17 && llegada == 16)
    {
        cout << "Tumaco -> Cali -> Medellin -> Bogota " << endl;
        cout << "Tumaco -> Cali -> Pasto -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 18)
    {
        cout << "Bogota -> Cucuta -> Medellin -> Cali " << endl;
        cout << "Bogota -> Cartagena -> Medellin -> Cali " << endl;

    }
    if (salida == 18 && llegada == 16)
    {
        cout << "Cali -> Medellin -> Cucuta -> Bogota " << endl;
        cout << "Cali -> Medellin -> Cartagena -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 19)
    {
        cout << "Bogota -> Medellin -> Cali -> Pasto " << endl;
        cout << "Bogota -> Cartagena -> Cali -> Pasto " << endl;

    }
    if (salida == 19 && llegada == 16)
    {
        cout << "Pasto -> Cali -> Medellin -> Bogota " << endl;
        cout << "Pasto -> Cali -> Cartagena -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 20)
    {
        cout << "Bogota -> Manizales -> Bogota -> Popayan " << endl;
        cout << "Bogota -> Villavicencio -> Bogota -> Popayan " << endl;

    }
    if (salida == 20 && llegada == 16)
    {
        cout << "Popayan -> Bogota -> Manizales -> Bogota " << endl;
        cout << "Popayan -> Bogota -> Villavicencio -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 21)
    {
        cout << "Bogota -> Manizales -> Bogota -> Neiva " << endl;
        cout << "Bogota -> Villavicencio -> Bogota -> Neiva " << endl;

    }
    if (salida == 21 && llegada == 16)
    {
        cout << "Neiva -> Bogota -> Manizales -> Bogota " << endl;
        cout << "Neiva -> Bogota -> Villavicencio -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 22)
    {
        cout << "Bogota -> Manizales -> Bogota -> Villavicencio " << endl;
        cout << "Bogota -> Yopal -> Bogota -> Villavicencio " << endl;

    }
    if (salida == 22 && llegada == 16)
    {
        cout << "Villavicencio -> Bogota -> Manizales -> Bogota " << endl;
        cout << "Villavicencio -> Bogota -> Yopal -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 23)
    {
        cout << "Bogota -> Manizales -> Bogota -> Leticia " << endl;
        cout << "Bogota -> Yopal -> Bogota -> Leticia " << endl;

    }
    if (salida == 23 && llegada == 16)
    {
        cout << "Leticia -> Bogota -> Manizales -> Bogota " << endl;
        cout << "Leticia -> Bogota -> Yopal -> Bogota " << endl;

    }
    if (salida == 16 && llegada == 24)
    {
        cout << "Bogota -> Manizales -> Bogota -> Florencia " << endl;
        cout << "Bogota -> Yopal -> Bogota -> Florencia " << endl;

    }
    if (salida == 24 && llegada == 16)
    {
        cout << "Florencia -> Bogota -> Manizales -> Bogota " << endl;
        cout << "Florencia -> Bogota -> Yopal -> Bogota " << endl;

    }
    if (salida == 18 && llegada == 0)
    {
        cout << "Cali -> Medellin -> Bogota -> San Andres" << endl;
        cout << "Cali ->  Barranquilla -> Bogota -> San Andres " << endl;

    }
    if (salida == 0 && llegada == 18)
    {
        cout << "San Andres ->  Bogota -> Medellin -> Cali " << endl;
        cout << "San Andres -> Bogota -> Barranquilla -> Cali " << endl;;
    }

    if (salida == 18 && llegada == 1)
    {
        cout << "Cali -> Medellin -> Bogota -> Cartagena" << endl;
        cout << "Cali -> Pasto -> Bogota -> Cartagena " << endl;

    }
    if (salida == 1 && llegada == 18)
    {
        cout << "Cartagena -> Bogota -> Medellin -> Cali " << endl;
        cout << "Cartagena -> Bogota -> Pasto ->Cali " << endl;
    }

    if (salida == 18 && llegada == 2)
    {
        cout << "Cali -> Medellin -> Bogota -> Barranquilla " << endl;
        cout << "Cali -> Pasto -> Bogota -> Barranquilla " << endl;
    }
    if (salida == 2 && llegada == 18)
    {
        cout << "Barranquilla -> Bogota -> Medellin -> Cali " << endl;
        cout << "Barranquilla -> Bogota -> Pasto -> Cali " << endl;
    }

    if (salida == 18 && llegada == 3)
    {
        cout << "Cali -> Cartagena -> Bogota -> Santa Marta " << endl;
        cout << "Cali -> Medellin -> Bogota -> Santa Marta " << endl;

    }
    if (salida == 3 && llegada == 18)
    {
        cout << "Santa Marta -> Bogota -> Cartagena -> Cali " << endl;
        cout << "Santa Marta -> Bogota -> Medellin -> Cali " << endl;
    }

    if (salida == 18 && llegada == 4)
    {
        cout << "Cali -> Medellin -> Bogota -> Riohacha" << endl;
        cout << "Cali -> Barranquilla -> Bogota -> Riohacha" << endl;
    }
    if (salida == 4 && llegada == 18)
    {
        cout << "Riohacha -> Bogota -> Medellino -> Cali " << endl;
        cout << "Riohacha -> Bogota -> Barranquilla -> Cali" << endl;

    }

    if (salida == 18 && llegada == 5)
    {
        cout << "Cali -> Medellin -> Bogota -> Monteria" << endl;
        cout << "Cali -> Bucaramanga -> Bogota -> Monteria" << endl;
    }
    if (salida == 5 && llegada == 18)
    {
        cout << "Monteria -> Bogota -> Medellin -> Cali" << endl;
        cout << "Monteria -> Bogota -> Bucaramanga -> Cali" << endl;
    }

    if (salida == 18 && llegada == 6)
    {
        cout << "Cali -> Cartagena -> Bogota -> Valledupar" << endl;
        cout << "Cali -> Bucaramanga -> Bogota -> Valledupar" << endl;
    }
    if (salida == 6 && llegada == 18)
    {
        cout << "Valledupar -> Bogota -> Cartagena -> Cali" << endl;
        cout << "Valledupar -> Bogota -> Bucaramanga -> Cali" << endl;
    }

    if (salida == 18 && llegada == 7)
    {
        cout << "Cali -> Cartagena -> Bogota -> Valledupar" << endl;
        cout << "Cali -> Bucaramanga -> Bogota -> Valledupar" << endl;
    }
    if (salida == 7 && llegada == 18)
    {
        cout << "Valledupar -> Bogota -> Cartagena -> Cali" << endl;
        cout << "Valledupar -> Bogota -> Bucaramanga -> Cali" << endl;
    }

    if (salida == 18 && llegada == 8)
    {
        cout << "Cali -> Cartagena -> Bogota -> Barrancabermeja" << endl;
        cout << "Cali -> Bucaramanga -> Bogota -> Barrancabermeja" << endl;
    }
    if (salida == 8 && llegada == 18)
    {
        cout << "Barrancabermeja -> Bogota -> Cartagena -> Cali" << endl;
        cout << "Barrancabermeja -> Bogota -> Bucaramanga -> Cali" << endl;
    }

    if (salida == 18 && llegada == 9)
    {
        cout << "Cali -> Cartagena -> Bogota -> Bucaramanga" << endl;
        cout << "Cali -> Barranquilla -> Bogota -> Bucaramanga" << endl;
    }
    if (salida == 9 && llegada == 18)
    {
        cout << "Bucaramanga -> Bogota -> Cartagena -> Cali" << endl;
        cout << "Bucaramanga -> Bogota -> Barranquilla -> Cali" << endl;
    }

    if (salida == 18 && llegada == 10)
    {
        cout << "Cali -> Cartagena -> Bogota -> Cucuta" << endl;
        cout << "Cali -> Barranquilla -> Bogota -> Cucuta" << endl;
    }
    if (salida == 10 && llegada == 18)
    {
        cout << "Cucuta -> Bogota -> Cartagena -> Cali" << endl;
        cout << "Cucuta -> Bogota -> Barranquilla -> Cali" << endl;
    }

    if (salida == 18 && llegada == 11)
    {
        cout << "Cali -> Cartagena -> Bogota -> Armenia" << endl;
        cout << "Cali -> Barranquilla -> Bogota -> Armenia" << endl;
    }
    if (salida == 11 && llegada == 18)
    {
        cout << "Armenia -> Bogota -> Cartagena -> Cali" << endl;
        cout << "Armenia -> Bogota -> Barranquilla -> Cali" << endl;
    }

    if (salida == 18 && llegada == 12)
    {
        cout << "Cali -> Cartagena -> Bogota -> Pereira" << endl;
        cout << "Cali -> Barranquilla -> Bogota -> Pereira" << endl;
    }
    if (salida == 12 && llegada == 18)
    {
        cout << "Pereira -> Bogota -> Cartagena -> Cali" << endl;
        cout << "Pereira -> Bogota -> Barranquilla -> Cali" << endl;
    }


    if (salida == 18 && llegada == 13)
    {
        cout << "Cali -> Cartagena -> Bogota -> Manizales" << endl;
        cout << "Cali -> Barranquilla -> Bogota -> Manizales" << endl;
    }
    if (salida == 13 && llegada == 18)
    {
        cout << "Manizales -> Bogota -> Cartagena -> Cali" << endl;
        cout << "Manizales -> Bogota -> Barranquilla -> Cali" << endl;
    }


    if (salida == 18 && llegada == 14)
    {
        cout << "Cali -> Cartagena -> Bogota -> Yopal" << endl;
        cout << "Cali -> Barranquilla -> Bogota -> Yopal" << endl;
    }
    if (salida == 14 && llegada == 18)
    {
        cout << "Yopal -> Bogota -> Cartagena -> Cali" << endl;
        cout << "Yopal -> Bogota -> Barranquilla -> Cali" << endl;
    }


    if (salida == 18 && llegada == 15)
    {
        cout << "Cali -> Cartagena -> Bogota -> Ibague" << endl;
        cout << "Cali -> Barranquilla -> Bogota -> Ibague" << endl;
    }
    if (salida == 15 && llegada == 18)
    {
        cout << "Ibague -> Bogota -> Cartagena -> Cali" << endl;
        cout << "Ibague -> Bogota -> Barranquilla -> Cali" << endl;
    }

    if (salida == 18 && llegada == 16)
    {
        cout << "Cali -> Medellin -> Bucaramanga -> Bogota" << endl;
        cout << "Cali -> Medellin -> Cucuta -> Bogota" << endl;
    }
    if (salida == 16 && llegada == 18)
    {
        cout << "Bogota -> Bucaramanga -> Medellin -> Cali" << endl;
        cout << "Bogota -> Cucuta -> Medellin -> Cali" << endl;
    }

    if (salida == 18 && llegada == 17)
    {
        cout << "Cali -> Cartagena -> Cali -> Tumaco" << endl;
        cout << "Cali -> Barranquilla -> Cali -> Tumaco" << endl;
    }
    if (salida == 15 && llegada == 17)
    {
        cout << "Tumaco -> Cali -> Cartagena -> Cali" << endl;
        cout << "Tumaco -> Cali -> Barranquilla -> Cali" << endl;
    }

    if (salida == 18 && llegada == 19)
    {
        cout << "Cali -> Bucaramanga -> Bogota -> Pasto" << endl;
        cout << "Cali -> Medellin -> Bogota -> Pasto" << endl;
    }
    if (salida == 19 && llegada == 18)
    {
        cout << "Pasto -> Bogota -> Bucaramanga -> Cali" << endl;
        cout << "Pasto -> Bogota -> Medellin -> Cali" << endl;
    }

    if (salida == 18 && llegada == 20)
    {
        cout << "Cali -> Bucaramanga -> Bogota -> Popayan" << endl;
        cout << "Cali -> Medellin -> Bogota -> Popayan" << endl;
    }
    if (salida == 20 && llegada == 18)
    {
        cout << "Popayan -> Bogota -> Bucaramanga -> Cali" << endl;
        cout << "Popayan -> Bogota -> Medellin -> Cali" << endl;
    }
    if (salida == 18 && llegada == 21)
    {
        cout << "Cali -> Bucaramanga -> Bogota -> Neiva" << endl;
        cout << "Cali -> Medellin -> Bogota -> Neiva" << endl;
    }
    if (salida == 21 && llegada == 18)
    {
        cout << "Neiva -> Bogota -> Bucaramanga -> Cali" << endl;
        cout << "Neiva -> Bogota -> Medellin -> Cali" << endl;
    }
    if (salida == 18 && llegada == 22)
    {
        cout << "Cali -> Bucaramanga -> Bogota -> Villavicencio" << endl;
        cout << "Cali -> Medellin -> Bogota -> Villavicencio" << endl;
    }
    if (salida == 22 && llegada == 18)
    {
        cout << "Villavicencio -> Bogota -> Bucaramanga -> Cali" << endl;
        cout << "Villavicencio -> Bogota -> Medellin -> Cali" << endl;
    }
    if (salida == 18 && llegada == 23)
    {
        cout << "Cali -> Bucaramanga -> Bogota -> Leticia" << endl;
        cout << "Cali -> Medellin -> Bogota -> Leticia" << endl;
    }
    if (salida == 23 && llegada == 18)
    {
        cout << "Leticia -> Bogota -> Bucaramanga -> Cali" << endl;
        cout << "Leticia -> Bogota -> Medellin -> Cali" << endl;
    }
    if (salida == 18 && llegada == 24)
    {
        cout << "Cali -> Bucaramanga -> Bogota -> Florencia" << endl;
        cout << "Cali -> Medellin -> Bogota -> Florencia" << endl;
    }
    if (salida == 24 && llegada == 18)
    {
        cout << "Florencia -> Bogota -> Bucaramanga -> Cali" << endl;
        cout << "Florencia -> Bogota -> Medellin -> Cali" << endl;
    }

}
void matriz_validad_colombia(int filabuscada_colombia, int columnabuscada_colombia, bool matriznatural[25][25], bool matriz_1_escala[25][25], bool matriz_2_escalas[25][25], string llegada)
{
    if ((filabuscada_colombia == -1 || columnabuscada_colombia == -1 || filabuscada_colombia > 24 || columnabuscada_colombia > 24 || (filabuscada_colombia < 25 && columnabuscada_colombia == -1) || (filabuscada_colombia == -1 && columnabuscada_colombia < 25)))
    {
        cout << "No existe vuelo disponible a " << llegada << endl;
    }
    else
    {
        if (matriznatural[filabuscada_colombia][columnabuscada_colombia])
        {
            cout << "* Existe vuelo directo a " << llegada << endl;
        }
        if (matriz_1_escala[filabuscada_colombia][columnabuscada_colombia])
        {
            cout << "* Existe vuelo con 1 escala a " << llegada << endl;
            colombia_nombre_con_una_escala(filabuscada_colombia, columnabuscada_colombia);
        }
        if (matriz_2_escalas[filabuscada_colombia][columnabuscada_colombia])
        {
            cout << "* Existe vuelo con 2 escalas a " << llegada << endl;
            colombian_nombre_con_dos_escalas(filabuscada_colombia, columnabuscada_colombia);
        }
    }
}

void matriz_colombia_internacional(int filabuscada_colombia, int columnabuscada_colombia, bool matriznatural[25][25], bool matriz_1_escala[25][25], bool matriz_2_escalas[25][25], string llegada)
{
    if ((filabuscada_colombia == -1 || columnabuscada_colombia == -1 || filabuscada_colombia > 24 || columnabuscada_colombia > 24 || (filabuscada_colombia < 25 && columnabuscada_colombia == -1) || (filabuscada_colombia == -1 && columnabuscada_colombia < 25)))
    {
        cout << "No existe vuelo disponible a " << llegada << endl;
    }
    else
    {
        if (matriznatural[filabuscada_colombia][columnabuscada_colombia])
        {
            cout << "* Existe vuelo directo a " << llegada << endl;
        }
        if (matriz_1_escala[filabuscada_colombia][columnabuscada_colombia])
        {
            cout << "* Existe vuelo con 1 escala a " << llegada << endl;
            colombia_nombre_con_una_escala(filabuscada_colombia, columnabuscada_colombia);
        }
        if (matriz_2_escalas[filabuscada_colombia][columnabuscada_colombia])
        {
            cout << "* Existe vuelo con 2 escalas a " << llegada << endl;
            colombian_nombre_con_dos_escalas(filabuscada_colombia, columnabuscada_colombia);
        }
    }
}
void matriz_validad_internacional_a_colombia(int filabuscada_colombia, int columnabuscada_colombia, bool matriznatural[25][25], bool matriz_1_escala[25][25], bool matriz_2_escalas[25][25], string llegada, string salida)
{
    if ((filabuscada_colombia == -1 || columnabuscada_colombia == -1 || filabuscada_colombia > 24 || columnabuscada_colombia > 24 || (filabuscada_colombia < 25 && columnabuscada_colombia == -1) || (filabuscada_colombia == -1 && columnabuscada_colombia < 25)))
    {
        cout << "No existe vuelo disponible a " << llegada << endl;
    }
    else
    {
        if (matriznatural[filabuscada_colombia][columnabuscada_colombia] && (salida == "Medellin" || llegada == "Medellin"))
        {
            cout << "* Existe vuelo directo a Medellin" << endl;
        }
        if (matriz_1_escala[filabuscada_colombia][columnabuscada_colombia] && (salida == "Medellin" || llegada == "Medellin"))
        {
            cout << "* Existe vuelo con 1 escala a Medellin" << endl;
            colombia_nombre_con_una_escala(filabuscada_colombia, columnabuscada_colombia);
        }
        if (matriz_2_escalas[filabuscada_colombia][columnabuscada_colombia] && (salida == "Medellin" || llegada == "Medellin"))
        {
            cout << "* Existe vuelo con 2 escalas a Medellin" << endl;
            colombian_nombre_con_dos_escalas(filabuscada_colombia, columnabuscada_colombia);
        }

        if (matriznatural[filabuscada_colombia][columnabuscada_colombia] && (salida == "Cali" || llegada == "Cali"))
        {
            cout << "* Existe vuelo directo a Cali" << endl;
        }
        if (matriz_1_escala[filabuscada_colombia][columnabuscada_colombia] && (salida == "Cali" || llegada == "Cali"))
        {
            cout << "* Existe vuelo con 1 escala a Cali" << endl;
            colombia_nombre_con_una_escala(filabuscada_colombia, columnabuscada_colombia);
        }
        if (matriz_2_escalas[filabuscada_colombia][columnabuscada_colombia] && (salida == "Cali" || llegada == "Cali"))
        {
            cout << "* Existe vuelo con 2 escalas a Cali" << endl;
            colombian_nombre_con_dos_escalas(filabuscada_colombia, columnabuscada_colombia);
        }

        if (matriznatural[filabuscada_colombia][columnabuscada_colombia] && (salida == "Bogota" || llegada == "Bogota"))
        {
            cout << "* Existe vuelo directo a Bogota" << endl;
        }
        if (matriz_1_escala[filabuscada_colombia][columnabuscada_colombia] && (salida == "Bogota" || llegada == "Bogota"))
        {
            cout << "* Existe vuelo con 1 escala a Bogota" << endl;
            colombia_nombre_con_una_escala(filabuscada_colombia, columnabuscada_colombia);
        }
        if (matriz_2_escalas[filabuscada_colombia][columnabuscada_colombia] && (salida == "Bogota" || llegada == "Bogota"))
        {
            cout << "* Existe vuelo con 2 escalas a Bogota" << endl;
            colombian_nombre_con_dos_escalas(filabuscada_colombia, columnabuscada_colombia);
        }
    }
}

void peru() {
    int opcion = 0;
    int opcion_vuelos_internacionales = 0;
    string salida;
    string llegada;
    bool matriz1escala_peru[9][9];
    bool matriz2escala_peru[9][9];
    //vuelos con 1 escala
    multiplicar_matrices_peru(vuelos_peru, vuelos_peru, matriz1escala_peru);
    //vuelos con dos escala
    multiplicar_matrices_peru(matriz1escala_peru, vuelos_peru, matriz2escala_peru);
    //fin de matrices relacionadas con peru

    cout << "Lugar de salida: ";
    cin >> salida;
    cout << "Lugar de llegada: ";
    cin >> llegada;
    valida_vuelos_peru(salida, llegada);
    matriz_validad_peru(filabuscada, columnabuscada, vuelos_peru, matriz1escala_peru, matriz2escala_peru, llegada);
    getch();
}

void vuelos_intenacionales_op1() {
    int opcion = 0;
    int opcion_vuelos_internacionales = 0;
    string salida, llegada;

    bool matriz1escalainternacional[25][25];
    bool matriz2escalainternacional[25][25];
    multiplicar_matrices_internacionales(internacional, internacional, matriz1escalainternacional);
    multiplicar_matrices_internacionales(matriz1escalainternacional, internacional, matriz2escalainternacional);

    cout << "Lugar de salida: ";
    cin >> salida;
    cout << "Lugar de llegada: ";
    cin >> llegada;
    validar_vuelos_internacionales(salida, llegada);
    matriz_validad_internacional(filabuscada_internacional, columnabuscada_internacional, internacional, matriz1escalainternacional, matriz2escalainternacional, llegada);
    getch();

}
void vuelos_intenacionales_op2() {
    int opcion = 0;
    int opcion_vuelos_internacionales = 0;
    string salida, llegada;
    bool matriz1escala_peru[9][9];
    bool matriz2escala_peru[9][9];
    //vuelos con 1 escala
    multiplicar_matrices_peru(vuelos_peru, vuelos_peru, matriz1escala_peru);
    //vuelos con dos escala
    multiplicar_matrices_peru(matriz1escala_peru, vuelos_peru, matriz2escala_peru);
    //fin de matrices relacionadas con peru

    bool matriz1escalainternacional[25][25];
    bool matriz2escalainternacional[25][25];
    multiplicar_matrices_internacionales(internacional, internacional, matriz1escalainternacional);
    multiplicar_matrices_internacionales(matriz1escalainternacional, internacional, matriz2escalainternacional);
    cout << "Lugar de salida: ";
    cin >> salida;
    cout << "Lugar de llegada: ";
    cin >> llegada;
    validar_vuelos_internacionales(salida, llegada);
    valida_vuelos_peru(salida, llegada);
    if (internacional[filabuscada_internacional][24] == true || matriz1escalainternacional[filabuscada_internacional][24] == true || matriz2escalainternacional[filabuscada_internacional][24] == true)
    {
        cout << "Usted debe ir primero a lima y estas son las opciones: " << endl;
        matriz_validad_internacional_anacional(filabuscada_internacional, 24, internacional, matriz1escalainternacional, matriz2escalainternacional);
        cout << "\n Las opciones de vuelo Lima a " << llegada << " son:" << endl;
        matriz_validad_lima_provincia(4, columnabuscada, vuelos_peru, matriz1escala_peru, matriz2escala_peru, llegada);
    }
    else if (vuelos_peru[filabuscada][4] == true || matriz1escala_peru[filabuscada][4] == true || matriz2escala_peru[filabuscada][4] == true)
    {
        cout << "Usted debe ir primero a lima y estas son las opciones: " << endl;
        matriz_validad_nacional_alima(filabuscada, 4, vuelos_peru, matriz1escala_peru, matriz2escala_peru);
        cout << "\nLas opciones de vuelo Lima a " << llegada << " son:" << endl;
        matriz_validad_lima_aInternacional(24, columnabuscada_internacional, internacional, matriz1escalainternacional, matriz2escalainternacional, llegada);
    }
    getch();
}

void vuelos_colombia()
{
    int opcion = 0;
    int opcion_vuelos_colombia = 0;
    string salida, llegada;
    bool matriz1escala_colombia[25][25];
    bool matriz2escalas_colombia[25][25];

    multiplicar_matrices_colombia(colombia, colombia, matriz1escala_colombia);
    multiplicar_matrices_colombia(matriz1escala_colombia, colombia, matriz2escalas_colombia);

    cout << "Lugar de salida: ";
    cin >> salida;
    cout << "Lugar de llegada: ";
    cin >> llegada;

    valida_vuelos_colombianos(salida, llegada);
    matriz_validad_colombia(filabuscada_colombia, columnabuscada_colombia, colombia, matriz1escala_colombia, matriz2escalas_colombia, llegada);
    getch();
}
void vuelos_colombianos_op2() {
    int opcion = 0;
    string salida, llegada;

    bool matriz1escalainternacional[25][25];
    bool matriz2escalainternacional[25][25];
    multiplicar_matrices_internacionales(internacional, internacional, matriz1escalainternacional);
    multiplicar_matrices_internacionales(matriz1escalainternacional, internacional, matriz2escalainternacional);

    bool matriz1escala_colombia[25][25];
    bool matriz2escalas_colombia[25][25];

    multiplicar_matrices_colombia(colombia, colombia, matriz1escala_colombia);
    multiplicar_matrices_colombia(matriz1escala_colombia, colombia, matriz2escalas_colombia);

    cout << "Lugar de salida: ";
    cin >> salida;
    cout << "Lugar de llegada: ";
    cin >> llegada;
    validar_vuelos_internacionales(salida, llegada);
    valida_vuelos_colombianos(salida, llegada);
    if ((internacional[filabuscada_internacional][19] == true || matriz1escalainternacional[filabuscada_internacional][19] == true || matriz2escalainternacional[filabuscada_internacional][19] == true) || (internacional[filabuscada_internacional][20] == true || matriz1escalainternacional[filabuscada_internacional][20] == true || matriz2escalainternacional[filabuscada_internacional][20] == true) || (internacional[filabuscada_internacional][21] == true || matriz1escalainternacional[filabuscada_internacional][21] == true || matriz2escalainternacional[filabuscada_internacional][21] == true))
    {
        cout << "Usted debe ir primero a Medellin, Cali o Bogota y estas son las opciones: " << endl;
        matriz_validad_internacional(filabuscada_internacional, 19, internacional, matriz1escalainternacional, matriz2escalainternacional, "Medellin");

        matriz_validad_internacional(filabuscada_internacional, 21, internacional, matriz1escalainternacional, matriz2escalainternacional, "Cali");

        matriz_validad_internacional(filabuscada_internacional, 20, internacional, matriz1escalainternacional, matriz2escalainternacional, "Bogota");

        cout << "\n Las opciones de vuelo desde Medellin, Cali o Bogota a " << llegada << " son:" << endl;
        matriz_validad_colombia(7, columnabuscada_colombia, colombia, matriz1escala_colombia, matriz2escalas_colombia, llegada);
        matriz_validad_colombia(18, columnabuscada_colombia, colombia, matriz1escala_colombia, matriz2escalas_colombia, llegada);
        matriz_validad_colombia(16, columnabuscada_colombia, colombia, matriz1escala_colombia, matriz2escalas_colombia, llegada);
    }
    else if ((colombia[filabuscada_colombia][19] == true || matriz1escala_colombia[filabuscada_colombia][19] == true || matriz2escalas_colombia[filabuscada_colombia][19] == true) || (colombia[filabuscada_colombia][20] == true || matriz1escala_colombia[filabuscada_colombia][20] == true || matriz2escalas_colombia[filabuscada_colombia][20] == true) || (colombia[filabuscada_colombia][21] == true || matriz1escala_colombia[filabuscada_colombia][21] == true || matriz2escalas_colombia[filabuscada_colombia][21] == true))
    {
        cout << "Usted debe ir primero a Medellin, Cali o Bogota y estas son las opciones: " << endl;
        matriz_validad_colombia(filabuscada_colombia, 7, colombia, matriz1escala_colombia, matriz2escalas_colombia, llegada);
        matriz_validad_colombia(filabuscada_colombia, 18, colombia, matriz1escala_colombia, matriz2escalas_colombia, llegada);
        matriz_validad_colombia(filabuscada_colombia, 16, colombia, matriz1escala_colombia, matriz2escalas_colombia, llegada);
        cout << "\nLas opciones de vuelo Medellin, Cali o Bogota a " << llegada << " son:" << endl;
        matriz_validad_internacional(19, columnabuscada_internacional, internacional, matriz1escalainternacional, matriz2escalainternacional, llegada);
        matriz_validad_internacional(21, columnabuscada_internacional, internacional, matriz1escalainternacional, matriz2escalainternacional, llegada);
        matriz_validad_internacional(20, columnabuscada_internacional, internacional, matriz1escalainternacional, matriz2escalainternacional, llegada);
    }
    getch();
}
void creditos() {
    setlocale(LC_ALL, "");
    int tecla;

    Console::BackgroundColor = ConsoleColor::White;
    Console::ForegroundColor = ConsoleColor::Black;
    cout << "                                                ___                    _     _                                          " << endl;
    cout << "                                               (  _`\\                 ( ) _ ( )_                                        " << endl;
    cout << "                                               | ( (_) _ __   __     _| |(_)| ,_)   _     ___                           " << endl;
    cout << "                                               | |  _ ( '__)/'__`\\ /'_` || || |   /'_`\\ /',__)                          " << endl;
    cout << "                                               | (_( )| |  (  ___/( (_| || || |_ ( (_) )\\__, \\                          " << endl;
    cout << "                                               (____/'(_)  `\\____)`\\__,_)(_)`\\__)`\\___/'(____/                          " << endl;
    cout << "                                                                                                                        " << endl;
    cout << "                                                                                                                        " << endl;
    short x = 0, y = 7;

    for (y; y <= 20; y++) {
        Console::BackgroundColor = ConsoleColor::White;
        Console::ForegroundColor = ConsoleColor::Black;
        Console::SetCursorPosition(x, y);
        switch (y) {
        case 8:  cout << "                         __                                                                              "
            << "                                                                                                                  "; break;
        case 9: cout << "                       .'  '.                                                                            "
            << "                                                                                                                  "; break;
        case 10: cout << "                    .-'/  | 0|                                                                           "
            << "                                                                                                                  "; break;
        case 11: cout << "       ,       _.-'  ,|  /    `.                                                                         "
            << "                                                                                                                  "; break;
        case 12: cout << "      /|    .-'       `--''-._.'=================================-,                                      "
            << "                                                                                                                  "; break;
        case 13: cout << "      | '-'`        .___.--._)===================================|                                      "
            << "                                                                                                                  "; break;
        case 14: cout << "       |            .'      |          Integrantes               |                                      "
            << "                                                                                                                  "; break;
        case 15: cout << "        |     /,_.-'        |  Arroyo Ormeño, André Alonso       | "
            << "                                                                                                                  "; break;
        case 16: cout << "      _/   _.' (            |  Del Carpio Flores, Ariana Ileen   |                                      "
            << "                                                                                                                  "; break;
        case 17: cout << "     /  ,-' |  |            |  Diaz Espinoza, Carlos Gabriel     |                                      "
            << "                                                                                                                  "; break;
        case 18: cout << "     |  |    `-'            |  Ramirez Rodriguez, Diego          |                                      "
            << "                                                                                                                  "; break;
        case 19: cout << "      `-'                   '------------------------------------'                                      "
            << "                                                                                                                  ";
        case 20: Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(0, 20);
            cout << "........................................................................................................"
                << "............................................................................................................."; break;
        }
        Console::BackgroundColor = ConsoleColor::Black;
        (y == 20 ? ++x, y = 4 : x += 0);
        (x == 60 ? ++x, x = 2 : x += 0);
        _sleep(10);

    }
}

void menu_intenacional() {
    setlocale(LC_ALL, "");
    system("cls");
    int opcion;

    do {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\nAEROLÍNEA AIR LIMIT\n" << endl;
        cout << "1. Si usted sale desde o llega a cualquier lugar del mundo" << endl;
        cout << "2. Si su destino o lugar de salida es una ciudad del Peru (distinta a Lima)" << endl;
        cout << "3. VOLVER" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            system("cls");
            vuelos_intenacionales_op1();

            break;

        case 2:
            // Lista de instrucciones de la opción 2                
            system("cls");
            vuelos_intenacionales_op2();
            break;
        case 3:
            break;



        }
    } while (opcion != 3);
}

void menu_colombia() {
    setlocale(LC_ALL, "");
    system("cls");
    int opcion;

    do {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\nAEROLÍNEA AIR LIMIT\n" << endl;
        cout << "1. Si usted quiere viajar dentro de colombia" << endl;
        cout << "2. Si su destino o lugar de salida es otro pais o lugar de colombia " << endl;
        cout << "3. VOLVER" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            system("cls");
            vuelos_colombia();

            break;

        case 2:
            // Lista de instrucciones de la opción 2                
            system("cls");
            vuelos_colombianos_op2();
            break;
        case 3:
            break;



        }
    } while (opcion != 3);
}
void menu_destinos() {
    setlocale(LC_ALL, "");
    system("cls");
    int opcion;

    do {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\nAEROLÍNEA AIR LIMIT\n" << endl;
        cout << "1. VUELOS PERÚ" << endl;
        cout << "2. VUELOS INTERNACIONALES" << endl;
        cout << "3. VUELOS COLOMBIA" << endl;
        cout << "4. VOLVER AL MENÚ DE OPCIONES" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:

            system("cls");
            peru();
            break;

        case 2:
            // Lista de instrucciones de la opción 2                
            system("cls");
            menu_intenacional();
            break;
        case 3:
            system("cls");
            menu_colombia();
            break;
        case 4:
            break;
        }
    } while (opcion != 4);


    getch();
    system("cls");
}
void menu() {
    system("cls");
    int opcion;

    do {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. VIAJES" << endl;
        cout << "2. CREDITOS" << endl;
        cout << "3. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Lista de instrucciones de la opción 1        
            system("cls");
            menu_destinos();
            break;
            -
        case 2:
            // Lista de instrucciones de la opción 2                
            system("cls");
            creditos();
            break;
        case 3:
            exit(0);
            break;
        }
    } while (true);


}

void pantalla_inicio() {

    char tecla;

    cout << " .    .   .       .       .       .       .       .       .       .       .       .      .  . .   . .          .  .  " << endl;
    cout << "    .   .   .  .    .  .    .  .    .  .    .  .    .  .    .  . .   . .  . .   . .  .  .    .  .    .  .  .    . . ." << endl;
    cout << " .    .      .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .  .   .   . .   . .  . .   " << endl;
    cout << "  ""  ___  _             _     _           _ _     .   .   .  . .   . .  . .   . .      . :;S@@8@St.              . ." << endl;
    cout << " ."" / _ \\(_)           | |   (_)         (_) |    |     .    . .   . .  . .   . .   .:%@88@X@X;%8; 8:::. .         ." << endl;
    cout << "  ""/ /_\\ \\_ _ __ ______| |    _ _ __ ___  _| |_ . .   . .   . .  . .   . .      . .t888888@XS8X8X@.%@X88% .         " << endl;
    cout << " .""|  _  | | '__|______| |   | | '_ ` _ \\| | __|    .  . .   . .  . .   . .    .:%@888888@X@t SSX:XX@XXSt%;         " << endl;
    cout << "  ""| | | | | |         | |___| | | | | | | | |_  |_|.  . .   . .  . .   . .  .:%@888888;X.XXXXX;%XXXXXSt:.tX   .    " << endl;
    cout << ". \\_| |_/_|_|         \\_____/_|_| |_| |_|_|\\__| .  . .   . .  . .   . .   .;8@88@88XX@88@XX@XXXXX@XXt:.:%t  .     ." << endl;
    cout << "   .   .   .  .      .  . . .    . .  .     .       .       .       .      :%@8888888:.SXX:%;@XXX@XXXSt:..t8;     .  " << endl;
    cout << ".    .      .   .  .           .     .t:  .   . .     . .     . .     .:%@888888%@;XX%X:XXXXXXX@XXS%:..:S@:.  .:t    " << endl;
    cout << ".    .   .       .   . .  .  .    . %X88%         .  .    .  .    . .;@@@8@@88XX @ 8XX@XX@X@XXXXXt..:.t8.     %X.8. ." << endl;
    cout << "   .   .   .  .    .       .   .   @88888%t .  .   .    .   .   ..t@8888888%88SXS:%XXXX@XXXXXXS;:.::%8;     . %88;X  " << endl;
    cout << ".    .      .   .  .;. . .       . :888%888:%    .    .   .  .t@888888@t;SX%@%SSSSX@XXXXXXX%t:.:. ;@888St888;S8t88S;." << endl;
    cout << ".    .   .       . S@8      . .     t8888%X88S.     .      :X8@@@X8X%t:S888@S8t@8SS@XX@XX%:..:.:88:8@8@888.;;8:8%@@  " << endl;
    cout << "   .   .   .  .    88;X.  .     .    S8SS8;8t8@8SSX8888XX:888XX8X@@S@@888888:8.8%%;XXX%t:.:..888%tS8tt8;X8;:.88tX. . " << endl;
    cout << ".    .      .   .  @88:8.SSS%XtX.8X88888;88.88:88 8 88.88.888.88X%t : 8%8..8;: t8tS%;:.: ;@S8.8;;%t8 t.8;8@t:.::.    " << endl;
    cout << ".    .   .       . %.8888.88.888888888%8::8:8;8;8:8:8t8;8:8%8@ t S 8.X:8X8:8 8;St;.... 8%88;8:%ttttt8. StS. : ..  .  " << endl;
    cout << "   .   .   .  .    %8ttt:8S8:.::::...8:8.8;8;8:8;8:8;8:8:8;88:t%%%%SX:  ;. .t;t:..:t88@@8%t@ tttttt%S88@X. ... .    ." << endl;
    cout << ".    .      .   .  :       .;;;ttt%%;:t;%@S88X@ :X.@@XXXXXXXSttttttt%@88@:%;:.:t88;...  .  8tttttttt .8t     .  .    " << endl;
    cout << ".    .   .       . .   .   .  .  .   . . @8;SSSXSS8%.@XXXX%ttttttttt%%t ...:8@:..  .      .X;tttt X% .  .    .   .  ." << endl;
    cout << "   .   .   .  .  . .  .     .  .  .  .  .S%:S;8%XXSX8.XXXX@X: %tttt;   .;%8@t:        .  .  .;X@X%:  .    . .   .   ." << endl;
    cout << ".    .      .   .     .   X888@S%8S88X88.8.::8%8%X@XS8%XX@XXXS%;:..:tX8%:..   . . .  .    .            .      .   .  " << endl;
    cout << ".    .   .       . .  .  888.t;;:%8888:8.8;:88%SXXXXX%XXXXXS%;..:S8t.               .  .     .  .  .  .  .  .        " << endl;
    cout << "   .   .   .  .         .:%S8S8S@S88X8@X8S%8@8888888X8X8S@XX@88%;.    .   . .  .  .      .     .    .          . .  ." << endl;
    cout << ".    .      .   .   .   .    .      .  .. .......::..... .  ..    . .   .            .     . .   .     .  .  .       " << endl;
    cout << ".    .   .       .     ..    .   .                     .        .          . . .  .    . .         .  .    .    . .  " << endl;
    cout << "   .   .   .  .      .     .   .   .     .    .  .  .    .    .    . . . .          .      .  . .   .   .    .       " << endl;
    cout << ".    .      .   .  .    .           Persione <<Espacio> para empezar a viajar     .  . .   .  .      . .   .   .  .  " << endl;
    cout << ".    .   .       .    .  .   .   .     .      . .   .   .    .     .  .  .         .   .  . . .      . .    .        " << endl;
    do
    {


        if (_kbhit())
        {
            tecla = getch();
            if (tecla == 32)
            {
                menu();
            }
        }
    } while (true);
}


int main()
{
    pantalla_inicio();
    getch();
    return 0;

}