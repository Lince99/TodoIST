/*
 * Copyright (C) 2019 Lince99
 *   for more info contact me at https://github.com/Lince99
 * This program is under MIT license
 *   for the file refer to LICENSE under TodoIST directory
 */
/*
 * json copied from official json website at https://www.json.org/example.html
 * and is under public domain
 * json reader from Tencent/rapidjson v1.1.0 at https://github.com/Tencent/rapidjson
 * and a copy of the license can be found at https://github.com/Tencent/rapidjson/blob/master/license.txt
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

/*
 * Class that read the content of json file
 */
class Reader {
    private:
        string data;
    public:
        Reader() {
        }

        /* Method that saves the content of the file into the string */
        string readFile(string filename) {
            string data = NULL;
            fstream json = NULL;
            json(filename, ios::in);

            json.open("myfile.txt", fstream::in);



            //open file with C functions

            return data;
        }
}

int main(int argc, char const *argv[]) {

    return 0;
}
