/*
 * Copyright (C) 2019 Lince99
 *   for more info contact me at https://github.com/Lince99
 * This program is under MIT license
 *   for the file refer to LICENSE under TodoIST directory
 */
/*
 * Api that provide various methods that open
 */
#include <fstream>
#include "logging.h"
#include "colors.h"

class JsonReader {

    private:
        string filename;
        ofstream filePtr;

        /* set & get */
        void setFilename(string new) {
            this.filename = new;
        }
        string getFilename() {
            return this.filename;
        }
        setfilePtr(ofstream ptr) {
            this.filePtr = ptr;
        }

        /* function that open */
        //TODO complete readFile
        void readFile(string filepath) {
            string line = NULL;

            try {
            ifstream in(filepath, ios_base::in); // read file in read
            getline(in, line);

            in.close();
        }

    public:
        /* contructors */
        JsonReader() {
            filename = NULL;
            filePtr = NULL;
        }
        JsonReader(string ptr) {
            filename = ptr;
            filePtr = NULL;
        }
}
