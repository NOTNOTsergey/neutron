//Neutron project
//Default initialization application

#include "nlib.h"
#include "app_desc.h"

void main(void* args){
    //A temporary buffer for messages
    char buf[256];
    //Print some info
    sprintf(buf, "Neutron standard initializer version %s\nCompiled on %s %s",
                 __APP_VERSION, __DATE__, __TIME__);
    _gfx_println_verbose(buf);
    //Open config file for reading
    _gfx_println_verbose("Loading config file");
    FILE* fp = fopen("/initrd/init.cfg", "r");
    if(fp == NULL){
        _gfx_println_verbose("[ ERROR ] Error loading config file (/initrd/init.cfg)");
        while(1);
    }
    //Read data by lines
    char line[512];
    uint64_t line_no = 0;
    while(true){
        //Read one line
        fgets(line, 512, fp);
        //If it's empty, EOF has been reached
        if(strlen(line) == 0)
            break;
        //Skip the line if it's empty or starts with a hash
        if(line[0] == '\n' || line[0] == '#'){
            line_no++;
            continue;
        }
        //Truncate the trailing \n
        if(line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        //Get key and value
        char key[256];
        char val[256];
        memset(key, 0, sizeof(key));
        memset(val, 0, sizeof(val));
        //Find occurence of the equal signkey
        char* eq_occur = strchr(line, '=');
        memcpy(key, line, eq_occur - line);
        strcpy(val, eq_occur + 1);

        memset(buf, 0, 256);

        //Parse the commands
        if(strcmp(key, "start") == 0){ //Start an application
            //Load the specified application
            uint64_t status = _task_load(val);
            //Print an error or a success message
            if(status == ELF_STATUS_OK){
                sprintf(buf, "[ START ] Started application %s", val);
                _gfx_println_verbose(buf);
            } else {
                sprintf(buf, "[ ERROR ] Error starting application %s", val);
                _gfx_println_verbose(buf);
            }
        } else { //Unknown command
            sprintf(buf, "[ ERROR ] Unknown command %s", key);
            _gfx_println_verbose(buf);
        }

        //Increment the line number
        line_no++;
    }

    while(1);
}