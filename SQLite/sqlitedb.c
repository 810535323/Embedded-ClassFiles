#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#define DATABASE "stu.db"

int do_insert(sqlite3 * db)
{
    int id;
    char name[32]={},sql[128]={};
    int score;
    char *errmsg;

    printf("Input id:->");
    scanf("%d",&id);

    printf("Input name:->");
    scanf("%s",name);

    printf("Input score:->");
    scanf("%d",&score);
    
    sprintf(sql,"insert into stu values(%d,'%s',%d);",id,name,score);

    if(sqlite3_exec(db,sql,NULL,NULL,&errmsg)!= SQLITE_OK)
    {
        printf("%s\n",errmsg);
    }else
    {
        printf("Insert done.\n");
    }
    return 0;
}

int do_delete(sqlite3 * db)
{
    int id;
    char name[32]={},sql[128]={};
    int score;
    int choose=0;
    char *errmsg;
    while(1)
    {
        printf("please choos what to delete(id=1,name=2,score=3):other num to exit->");
        scanf("%d",&choose);
        getchar();
        switch(choose)
        {
        case 1:
            printf("Input id:->");
            scanf("%d",&id);
            getchar();

            sprintf(sql,"delete from stu where id=%d;",id);

            if(sqlite3_exec(db,sql,NULL,NULL,&errmsg) != SQLITE_OK)
            {
                printf("%s\n",errmsg);
            }else
            {
                printf("Id deleted\n");
            }
            break;
        case 2:
            printf("Input name:->");
            scanf("%s",name);
            getchar();

            sprintf(sql,"delete from stu where name='%s';",name);

            if(sqlite3_exec(db,sql,NULL,NULL,&errmsg) != SQLITE_OK)
            {
                printf("%s\n",errmsg);
            }else
            {
                printf("Name deleted\n");
            }
            break;
        case 3:
            printf("Input score:->");
            scanf("%d",&score);
            getchar();

            sprintf(sql,"delete from stu where score=%d;",score);

            if(sqlite3_exec(db,sql,NULL,NULL,&errmsg) != SQLITE_OK)
            {
                printf("%s\n",errmsg);
            }else
            {
                printf("Score deleted\n");
            }
            break;
        }
        if(choose<=0||choose>=4)
        {
            break;
        }
    }
    return 0;
}

int do_update(sqlite3 * db)
{
    int id,idn;
    char sql[128]={},namen[32]={};
    int scoren;
    int choose=0;
    char *errmsg;
    while(1)
    {
        printf("please choose what to update(id=1,name=2,score=3):other num to exit->");
        scanf("%d",&choose);
        getchar();
        switch(choose)
        {
        case 1:
            printf("Input update id:->");
            scanf("%d",&id);
            getchar();

            printf("Input new id:->");
            scanf("%d",&idn);
            getchar();
            
            sprintf(sql,"update stu set id=%d where id=%d",idn,id);

            if(sqlite3_exec(db,sql,NULL,NULL,&errmsg) != SQLITE_OK)
            {
                printf("%s\n",errmsg);
            }else
            {
                printf("Id updated\n");
            }
            break;
        case 2:
            printf("Input update id:->");
            scanf("%d",&id);
            getchar();

            printf("Input new name:->");
            scanf("%s",namen);
            getchar();

            sprintf(sql,"update stu set name='%s' where id=%d",namen,id);

            if(sqlite3_exec(db,sql,NULL,NULL,&errmsg) != SQLITE_OK)
            {
                printf("%s\n",errmsg);
            }else
            {
                printf("Name updated\n");
            }
            break;
        case 3:
            printf("Input update id:->");
            scanf("%d",&id);
            getchar();

            printf("Input new score:->");
            scanf("%d",&scoren);
            getchar();
            
            sprintf(sql,"update stu set score=%d where id=%d",scoren,id);

            if(sqlite3_exec(db,sql,NULL,NULL,&errmsg) != SQLITE_OK)
            {
                printf("%s\n",errmsg);
            }else
            {
                printf("Score updated\n");
            }
            break;
        }
        if(choose<=0||choose>=4)
        {
            break;
        }
    }
    return 0;
}
int callback(void *para,int f_num,char **f_value,char **f_name)
{
    int i=0;

    for(i=0;i<f_num;i++)
    {
        printf("%-11s",f_value[i]);
    }
    putchar(10);
    return 0;
}

int do_query(sqlite3 *db)
{
    char sql[128]={};
    char *errmsg;
    sprintf(sql,"select * from stu;");

    if(sqlite3_exec(db,sql,callback,NULL,&errmsg) != SQLITE_OK)
    {
        printf("%s\n",errmsg);
    }else
    {
        printf("Query done!\n");
    }
    return 0;
}


int do_query1(sqlite3 *db)
{
    char sql[128]={};
    char *errmsg;
    char **resultp;
    int nrow,ncloumn,i,j,index;

    sprintf(sql,"select * from stu;");

    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncloumn,&errmsg) != SQLITE_OK)
    {
        printf("%s\n",errmsg);
    }else
    {
        printf("Query done!\n");
    }
    for(j = 0;j < ncloumn; j++)
    {

        printf(" %11s ",resultp[j]);
    }
    putchar(10);
    index = ncloumn;
    for(i=0;i<nrow;i++)
    {
        for(j=0;j<ncloumn;j++)
        {
            printf(" %11s ",resultp[index++]);
        }
        putchar(10);
    }
    return 0;
}

int main()
{
    sqlite3 * db;
    int cmd;
    char *errmsg;
    if(sqlite3_open(DATABASE,&db) != SQLITE_OK)
    {
        printf("%s\n",sqlite3_errmsg(db));
        return -1;
    }
    else
    {
        printf("open DATABASE sucess.\n");
    }

    //创建数据表格
    if(sqlite3_exec(db,"create table stu (id Integer,name char,score Integer);",NULL,NULL,&errmsg)!= SQLITE_OK)
    {
        printf("%s\n",errmsg);
    }else
    {
        printf("create table or open success!\n");
    }
    while(1)
    {
        printf("************************************************\n");
        printf("1:insert 2:delete 3：query 4:update 5:quit.\n");
        printf("************************************************\n");
        scanf("%d",&cmd);
        getchar();

        switch(cmd)
        {
        case 1:
            do_insert(db);
            break;
        case 2:
            do_delete(db);
             break;
        case 3:
            //do_query(db);
            do_query1(db);
            break;
        case 4:
            do_update(db);
            break;
        case 5:
            sqlite3_close(db);
            exit(0);
        default:
            printf("error command!\n");

        }
    }
    return 0;
}
