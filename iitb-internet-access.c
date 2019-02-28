#include <stdio.h>
#include <curl/curl.h>
#include <ncurses.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

void ncurses_gui(int index);
int my_getch();
size_t filewrite_fn(void *ptr, size_t size, size_t nmemb, FILE *stream);
void ncurses_gui(int index){
    char prompt[] = "**IITB Internet Access**";
    int row, col;
    if(index ==0){
        initscr();
        getmaxyx(stdscr,row,col);
        move(1,0);hline(ACS_HLINE, col);
        move(3,0);hline(ACS_HLINE, col);
        mvprintw(2,(col-strlen(prompt))/2,prompt);
        refresh();
    }else if(index ==1){
        move(LINES-2,0);hline(ACS_HLINE, COLS);
        
        strcpy(prompt, "Done! (Press any key to exit..)");
        mvprintw(LINES-1,0,prompt);

        strcpy(prompt, "Log File: /tmp/tenretnibtii.log");
        mvprintw(LINES-1,COLS - strlen(prompt) -1,prompt);
        refresh();

        getch();
        endwin();
    }
}
int my_getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
size_t filewrite_fn(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

int main(void){
    CURL *curl;
    CURLcode res;
    char uname[100], prompt[100];
    char passwd[100], ch;
    int i=0;

    curl = curl_easy_init();
    ncurses_gui(0);
    strcpy(prompt, "Username:");
    mvprintw(5,0,prompt);
    getstr(uname);
    strcpy(prompt, "Password:");
    mvprintw(6,0,prompt);
    refresh();
    i=0;
    while(1){
        ch = my_getch();
        if(ch == 13){
            // For Enter
            break;
        }else if((ch == 8)||(ch == 127)){
            // For Backspace or delete
            printf("\b \b");
        }else{
            printf("*");
            passwd[i] = ch;
            i++;
        }
    }
    passwd[i] = '\0';
    if(curl) {
        char data[100];
        FILE *outfile;
        outfile = fopen("/tmp/tenretnibtii.log", "w");

        strcpy(data, "uname=");
        strcat(data, uname);
        strcat(data, "&passwd=");
        strcat(data, passwd);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_URL, "https://internet.iitb.ac.in");
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, outfile);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, filewrite_fn);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
        curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    ncurses_gui(1);
    return 0;
}
