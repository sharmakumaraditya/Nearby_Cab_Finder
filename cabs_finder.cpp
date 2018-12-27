#include <bits/stdc++.h> 
using namespace std; 
   
#define latid 14.1225 
#define lonid 76.1048927 
#define pi 3.1415
#define earth_r 6371.0 
  
ifstream customer_list ("cabs_data.json"); 
ofstream out ("cars_near_you.json"); 
  
 
double deg_to_radian(double deg); 
double distanceEarth(double lat_id, double lon_id); 
 

struct json
{ 

    char latitude_as_string[1000],  
         longitude_as_string[1000],  
         id_as_string[1000], name[1000]; 
    double lat_id, lon_id; 
	string line;
    long long int length, i, j, x, y, m, 
                  n, f, fi, id[100000];
				  
    void distance_calculator() 
    { 
        if (distanceEarth(lat_id, lon_id) <= 20.0000) 
        { 
            id[i] = atoll(id_as_string); 
            i++; 
            out << "{\"id\": " << id[i - 1] <<  
                ", \"name\": " << name << "}" << endl; 
        } 
    } 
    void json_parser() 
    {                      
        if (customer_list.is_open()) 
        { 
              
            while (getline(customer_list, line)) 
            { 
                  
                f = 0; x = 0; y = 0; fi = 0; m = 0, n = 0; 
                length = line.size(); 
  
                for (j = 0; j < length; j++) 
                { 
                      
                    if (line[j] == '"') 
                        f++; 
  
                    else if (line[j] == ':') 
                        fi++; 
                          
                    if (f == 3) 
                    { 
                        j++; 
  
                        while (line[j] != '"') 
                        { 
                            latitude_as_string[x] = line[j]; 
                            x++; j++; 
                        } 
  
                        j--; latitude_as_string[x] = '\0'; 
                    } 
                      
                    else if (f == 13) 
                    { 
                        j++; 
  
                        while (line[j] != '"') 
                        { 
                            longitude_as_string[y] = line[j]; 
                            y++; j++; 
                        } 
  
                        j--; longitude_as_string[y] = '\0'; 
                    } 
                    if (fi == 2) 
                    { 
                        j += 2; 
  
                        while (line[j] != ',') 
                        { 
                            id_as_string[m] = line[j]; 
                            m++; j++; 
                        } 
  
                        j--; id_as_string[m] = '\0'; 
                        fi++; 
                    } 
                    else if (fi == 4) 
                    { 
                        j += 2; 
  
                        while (line[j] != ',') 
                        { 
                            name[n] = line[j]; 
                            n++; j++; 
                        } 
  
                        j--; name[n] = '\0'; 
                        fi++; f += 2; 
                    } 
                } 
                lat_id = atof(latitude_as_string); 
                lon_id = atof(longitude_as_string); 
                distance_calculator(); 
            } 
        } 
        customer_list.close(); 
        out.close(); 
    } 
}; 
  
int main() 
{ 
    json obj; 
    obj.json_parser(); 
    return 0; 
} 

double distanceEarth(double lat_id, double lon_id) 
{                  
    double lat_1, lon_1, lat_2, lon_2,  
           delta_lon, central_ang; 
    lat_1 = deg_to_radian(latid); 
    lon_1 = deg_to_radian(lonid); 
    lat_2 = deg_to_radian(lat_id); 
    lon_2 = deg_to_radian(lon_id); 
    delta_lon = lon_2 - lon_1;  
    central_ang = acos ( sin(lat_1) * 
                  sin(lat_2) + cos(lat_1) *        //great circle distance formulae
                  cos(lat_2) * cos(delta_lon) );  
    return (earth_r * central_ang);
}

double deg_to_radian(double deg) 
{ 
    return ( deg * pi / 180); 
} 