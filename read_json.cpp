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
 * and a copy of the license can bo found at https://github.com/Tencent/rapidjson/blob/master/license.txt
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;

/*
 * Class that read the content of json file
 */
class Reader {
    private:

    public:
        Reader() {

        }
}

/*int getSize() {
    fstream infile;
    infile.open(filename.c_str(),ios::in);
    infile.seekp(ios::end);
    int file_size=infile.tellp();
    cout<<"file size: "<<file_size<<endl;
}*/

int main(int argc, char const *argv[]) {
    /*https://github.com/Tencent/rapidjson/blob/master/example/jsonx/jsonx.cpp*/
    // Prepare JSON reader and input stream.
    Reader reader;
    char readBuffer[65536];
    FileReadStream is(stdin, readBuffer, sizeof(readBuffer));

    // Prepare JSON writer and output stream.
    char writeBuffer[65536];
    FileWriteStream os(stdout, writeBuffer, sizeof(writeBuffer));
    JsonxWriter<FileWriteStream> writer(os);

    // JSON reader parse from the input stream and let writer generate the output.
    if (!reader.Parse(is, writer)) {
        fprintf(stderr, "\nError(%u): %s\n", static_cast<unsigned>
                (reader.GetErrorOffset()),
                GetParseError_En(reader.GetParseErrorCode()));
        return 1;
    }
    return 0;
}
