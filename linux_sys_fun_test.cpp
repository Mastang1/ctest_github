#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
using namespace std;

static void sys_handler(int sig)
{
	printf("Current process be killed!");
}

int main(int argc ,char **argv)
{
	signal(SIGSTOP, sys_handler);//linux signal, like interrupt
	/**
	 * @brief ====通过system()函数执行date指令，获取时间
	 * 
	 */
	if(system("date") == -1){
		printf("execl filed!\n");
		
		perror("becasue");
	}
    


    /**
     * @brief =======测试 当前工作路径chdir 和 getcwd() 函数
     * 
     */
    
    char current_dir[100];
    

    getcwd(current_dir, 100);
    cout<<"cur_dir first: "<<current_dir<<endl;

    string std_str_cur_dir(current_dir);
    /******** 执行改变路径前，先判断路径是否存在 ****************/
    std_str_cur_dir.append("./tang_bin");               //采用c++的string类来处理字符串，确实方便
    if(access(std_str_cur_dir.c_str(), F_OK) == -1){
        cout<<"new directory is not saved!"<<endl;
        
        if(system("mkdir tang_bin") == -1){
		printf("execl filed!\n");
		
		perror("becasue");
	    }
    }else{
        cout<<"new directory is exist!"<<endl;
    }

    if(chdir("./tang_bin") == -1) cout<<"\n -- change directory failed!!!\n";
    
    getcwd(current_dir, 100);
    cout<<"cur_dir second:  "<<current_dir<<endl;
	return 0;
}

