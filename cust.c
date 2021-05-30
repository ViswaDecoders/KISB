#define MAX_COLOR 50
char ANSI_COLOR_RED[MAX_COLOR]="\x1b[31m";
char ANSI_COLOR_GREEN[MAX_COLOR]="\x1b[32m";
char ANSI_COLOR_YELLOW[MAX_COLOR]="\x1b[33m";
char ANSI_COLOR_BLUE[MAX_COLOR]="\x1b[34m";
char ANSI_COLOR_MAGENTA[MAX_COLOR]="\x1b[35m";
char ANSI_COLOR_CYAN[MAX_COLOR]="\x1b[36m";
char ANSI_COLOR_WHITE[MAX_COLOR]="\x1b[37m";
char ANSI_COLOR_BRIGHT_RED[MAX_COLOR]="\x1b[91m";
char ANSI_COLOR_BRIGHT_GREEN[MAX_COLOR]="\x1b[92m";
char ANSI_COLOR_BRIGHT_YELLOW[MAX_COLOR]="\x1b[93m";
char ANSI_COLOR_BRIGHT_BLUE[MAX_COLOR]="\x1b[94m";
char ANSI_COLOR_BRIGHT_MAGENTA[MAX_COLOR]="\x1b[95m";
char ANSI_COLOR_BRIGHT_CYAN[MAX_COLOR]="\x1b[96m";
char ANSI_COLOR_BRIGHT_WHITE[MAX_COLOR]="\x1b[97m";
char ANSI_COLOR_RESET[MAX_COLOR]="\x1b[0m";
char *curr_usr_color;
char *curr_dir_color;
char* init_color(){
    char *temp=(char*)malloc(sizeof(char)*MAX_COLOR);
    temp=ANSI_COLOR_RED;
    return temp;
}
void remove_EOF_color(char line[]) {
	int i = 0;
	while (line[i] != '\n')
		i++;
	line[i] = '\0';
}
void display_color(){
    printf("%sRED%s\n",ANSI_COLOR_RED,ANSI_COLOR_RESET);
    printf( "%sGREEN%s\n",ANSI_COLOR_GREEN,ANSI_COLOR_RESET);
    printf("%sYELLOW%s\n",ANSI_COLOR_YELLOW,ANSI_COLOR_RESET);
    printf("%sBLUE%s\n",ANSI_COLOR_BLUE,ANSI_COLOR_RESET );
    printf("%sMAGENTA%s\n" ,ANSI_COLOR_MAGENTA,ANSI_COLOR_RESET );
    printf("%sCYAN%s\n",ANSI_COLOR_CYAN,ANSI_COLOR_RESET );
    printf("%sWHITE%s\n",ANSI_COLOR_WHITE,ANSI_COLOR_RESET );
    printf("%sBRIGHT RED%s\n",ANSI_COLOR_BRIGHT_RED,ANSI_COLOR_RESET );
    printf("%sBRIGHT GREEN%s\n",ANSI_COLOR_BRIGHT_GREEN,ANSI_COLOR_RESET );
    printf("%sBRIGHT YELLOW%s\n",ANSI_COLOR_BRIGHT_YELLOW,ANSI_COLOR_RESET );
    printf("%sBRIGHT BLUE%s\n",ANSI_COLOR_BRIGHT_BLUE,ANSI_COLOR_RESET );
    printf("%sBRIGHT MAGENTA%s\n",ANSI_COLOR_BRIGHT_MAGENTA ,ANSI_COLOR_RESET );
    printf("%sBRIGHT CYAN%s\n",ANSI_COLOR_BRIGHT_CYAN,ANSI_COLOR_RESET );
    printf("%sBRIGHT WHITE%s\n",ANSI_COLOR_BRIGHT_WHITE,ANSI_COLOR_RESET );
 
}
char* update_color(){
    printf("Enter the correspoding color name in capitals\n");
    char color_new[MAX_COLOR];
    char*temp=fgets(color_new,MAX_COLOR,stdin);
    remove_EOF_color(color_new);
    if(!strcmp(temp,"RED")){
        temp=ANSI_COLOR_RED;
    }
    else if(!strcmp(temp,"GREEN")){
        temp=ANSI_COLOR_GREEN;
    }
    else if(!strcmp(temp,"YELLOW")){
        temp=ANSI_COLOR_YELLOW;
    }
    else if(!strcmp(temp,"BLUE")){
        temp=ANSI_COLOR_BLUE;
    }
    else if(!strcmp(temp,"MAGENTA")){
        temp=ANSI_COLOR_MAGENTA;
    }
    else if(!strcmp(temp,"CYAN")){
        temp=ANSI_COLOR_CYAN;
    }
    else if(!strcmp(temp,"WHITE")){
        temp=ANSI_COLOR_WHITE;
    }
    else if(!strcmp(temp,"BRIGHT RED")){
        temp=ANSI_COLOR_RED;
    }
    else if(!strcmp(temp,"BRIGHT GREEN")){
        temp=ANSI_COLOR_BRIGHT_RED;
    }
    else if(!strcmp(temp,"BRIGHT YELLOW")){
        temp=ANSI_COLOR_BRIGHT_YELLOW;
    }
    else if(!strcmp(temp,"BRIGHT BLUE")){
        temp=ANSI_COLOR_BRIGHT_BLUE;
    }
    else if(!strcmp(temp,"BRIGHT MAGENTA")){
        temp=ANSI_COLOR_BRIGHT_MAGENTA;
    }
    else if(!strcmp(temp,"BRIGHT WHITE")){
        temp=ANSI_COLOR_BRIGHT_WHITE;
    }
    else if(!strcmp(temp,"BRIGHT CYAN")){
        temp=ANSI_COLOR_BRIGHT_CYAN;
    }
    else{
        printf("ERR:Invalid color name\n");
        return ANSI_COLOR_BLUE;
    }
    printf("%sUpdated%s\n",temp,ANSI_COLOR_RESET);
    return temp;
    
}
