#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include <string.h>
#include <syslog.h>


int main(int argc, char* argv[]){

    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    if(argc < 3){
        printf("Insufficient arguments");
        syslog(LOG_ERR, "Insufficient arguments");
        return 1;
    }

    char* writestr = argv[2];


    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0664);  // Might cause an error due to not 
                                       // creating a file it doesn't exist
   

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, argv[1]);
    if(write(fd, writestr, strlen(writestr)) == -1){
        printf("File not created");
        syslog(LOG_ERR, "File not created");
        close(fd);
        return 1;
    }

    close(fd);
    closelog();

    return 0;
}
