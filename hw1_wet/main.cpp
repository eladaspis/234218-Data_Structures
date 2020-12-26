/***************************************************************************/
/*                                                                         */
/* 234218 Data DSs 1, Winter 2019-2020                                     */
/* Homework : Wet 1                                                        */
/*                                                                         */
/***************************************************************************/

/***************************************************************************/
/*                                                                         */
/* File Name : main1.cpp                                                   */
/*                                                                         */
/* Holds the "int main()" function and the parser of the shell's           */
/* command line.                                                           */
/***************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "boom.h"

#ifdef __cplusplus
extern "C" {
#endif

/* The command's strings */
typedef enum {
    NONE_CMD = -2,
    COMMENT_CMD = -1,
    INIT_CMD = 0,
    ADDCOURSE_CMD = 1,
    REMOVECOURSE_CMD = 2,
    WATCHCLASS_CMD = 3,
    TIMEVIEWED_CMD = 4,
    GETMOSTVIEWEDCLASSES_CMD = 5,
    QUIT_CMD = 6
} commandType;
//
//static const int numActions = 9;
//static const char *commandStr[] = {
//        "Init",
//        "AddCourse",
//        "RemoveCourse",
//        "WatchClass",
//        "TimeViewed",
//        "GetMostViewedClasses",
//        "Quit" };
//
//static const char* ReturnValToStr(int val) {
//    switch (val) {
//        case SUCCESS:
//            return "SUCCESS";
//        case ALLOCATION_ERROR:
//            return "ALLOCATION_ERROR";
//        case FAILURE:
//            return "FAILURE";
//        case INVALID_INPUT:
//            return "INVALID_INPUT";
//        default:
//            return "";
//    }
//}
//
///* we assume maximum string size is not longer than 256  */
//#define MAX_STRING_INPUT_SIZE (255)
//#define MAX_BUFFER_SIZE       (255)
//
//#define StrCmp(Src1,Src2) ( strncmp((Src1),(Src2),strlen(Src1)) == 0 )
//
//typedef enum {
//    error_free, error
//} errorType;
//static errorType parser(const char* const command);
//
#define ValidateRead(read_parameters,required_parameters,ErrorString,ErrorParams) \
if ( (read_parameters)!=(required_parameters) ) { printf(ErrorString, ErrorParams); return error; }
//
//static bool isInit = false;

/***************************************************************************/
/* main                                                                    */
/***************************************************************************/

int main(int argc, const char**argv) {

//    char buffer[MAX_STRING_INPUT_SIZE];

     //Reading commands
//    while (fgets(buffer, MAX_STRING_INPUT_SIZE, stdin) != NULL) {
//        fflush(stdout);
//        if (parser(buffer) == error)
//            break;
//    };
//    void* a=Init();
//    AddCourse(a,2,4);
//    WatchClass(a,2,2,5);
//    cout << *(Boom*) a <<endl;
//
//    Quit(&a);
//    cout << "*(Boom*) a" <<endl;

    //boom->AddCourse(6,9);
    //boom->RemoveCourse(4);
    //boom->RemoveCourse(8);
//    boom->WatchClass(5,2,8);
//    boom->WatchClass(1,3,20);
//    boom->WatchClass(5,0,6);
    //boom->WatchClass(5,0,5);

    //boom->WatchClass(5,0,5);
//    boom->WatchClass(5,3,5);
//    boom->WatchClass(5,0,5);
//    boom->WatchClass(5,2,1);
//    boom->WatchClass(5,1,1);
//    boom->WatchClass(5,3,1);
//    boom->WatchClass(5,0,1);
//    boom->RemoveCourse(5);
//    boom->RemoveCourse(1);
//    boom->RemoveCourse(2);

//    boom->AddCourse(5,5);
//    boom->AddCourse(2,5);
//    boom->AddCourse(0,5);

//    boom->AddCourse(3,5);
//    boom->AddCourse(4,5);
//    boom->AddCourse(5,5);
//    boom->WatchClass(1, 3, 10);
//    boom->WatchClass(2, 2, 10);
//    boom->WatchClass(1, 2, 10);
//    boom->WatchClass(2, 3, 10);
//    boom->WatchClass(5, 0, 10);
//    boom->WatchClass(5, 1, 10);
//    boom->WatchClass(5, 2, 5);


//    boom->WatchClass(0, 2, 5);


//    cout<<*boom<<endl;
    Boom* boom= new Boom();
    boom->AddCourse(234218 ,1);
//    boom->AddCourse(324694 ,5);
//    boom->AddCourse(234218  ,5);
    boom->RemoveCourse(234218);

//    boom->AddCourse(2,5);
//    boom->WatchClass(1,4,10);
//    int* courses = new int[5];
//    int* classes = new int[5];
//    boom->GetMostViewedClasses(3, courses, classes);
//    for (int i = 0; i < 5; ++i) {
//        cout << "Course: " << courses[i] << " Class: " <<  classes[i] << endl;
//    }
//    AVLTree<int, Course>* tree_ = new AVLTree<int, Course>();
//    AVLTree<int, Lecture>* p = new AVLTree<int,Lecture>();
//    for (int k = 0; k < 3; ++k) {
//        for (int i = 0; i < 2; ++i) {
//            Lecture* a = new Lecture(i);
//            p->insert(i,a);
//        }
//        Course* new_course=new Course(k,p);
//        tree_->insert(k,new_course);
//    }
//    cout << *tree_ <<endl;
//    delete tree_;
//    Course* x = new Course(5, p);
//    Course* y = new Course(*x);
//    delete x;
    //cout << *p <<endl;
//    AVLTree<int,int>* tree = new AVLTree<int, int>();
//    int a1=1;
//    int a2=2;
//    tree->insert(&a1, &a2);
//
//    cout << *tree->get_smallest_key() << endl;
//    cout << *tree->get_smallest_value() << endl;

//    AVLTree<int, int> tree =

    //boom->TimeViewed(4,x);
//    cout << "------------------------=---------------------" <<endl;

//    cout << *boom <<endl;

    delete boom;

    return 0;
}

/***************************************************************************/
/* Command Checker                                                         */
/***************************************************************************/
//
//static commandType CheckCommand(const char* const command,
//                                const char** const command_arg) {
//    if (command == NULL || strlen(command) == 0 || StrCmp("\n", command))
//        return (NONE_CMD);
//    if (StrCmp("#", command)) {
//        if (strlen(command) > 1)
//            printf("%s", command);
//        return (COMMENT_CMD);
//    };
//    for (int index = 0; index < numActions; index++) {
//        if (StrCmp(commandStr[index], command)) {
//            *command_arg = command + strlen(commandStr[index]) + 1;
//            return ((commandType)index);
//        };
//    };
//    return (NONE_CMD);
//}
//
///***************************************************************************/
///* Commands Functions                                                      */
///***************************************************************************/
//
//static errorType OnInit(void** DS, const char* const command);
//static errorType OnAddCourse(void* DS, const char* const command);
//static errorType OnRemoveCourse(void* DS, const char* const command);
//static errorType OnWatchClass(void* DS, const char* const command);
//static errorType OnTimeViewed(void* DS, const char* const command);
//static errorType OnGetMostViewedClasses(void* DS, const char* const command);
//static errorType OnQuit(void** DS, const char* const command);
//
///***************************************************************************/
///* Parser                                                                  */
///***************************************************************************/
//
//static errorType parser(const char* const command) {
//    static void *DS = NULL; /* The general data structure */
//    const char* command_args = NULL;
//    errorType rtn_val = error;
//
//    commandType command_val = CheckCommand(command, &command_args);
//
//    switch (command_val) {
//
//        case (INIT_CMD):
//            rtn_val = OnInit(&DS, command_args);
//            break;
//        case (ADDCOURSE_CMD):
//            rtn_val = OnAddCourse(DS, command_args);
//            break;
//        case (REMOVECOURSE_CMD):
//            rtn_val = OnRemoveCourse(DS, command_args);
//            break;
//        case (WATCHCLASS_CMD):
//            rtn_val = OnWatchClass(DS, command_args);
//            break;
//        case (TIMEVIEWED_CMD):
//            rtn_val = OnTimeViewed(DS, command_args);
//            break;
//        case (GETMOSTVIEWEDCLASSES_CMD):
//            rtn_val = OnGetMostViewedClasses(DS, command_args);
//            break;
//        case (QUIT_CMD):
//            rtn_val = OnQuit(&DS, command_args);
//            break;
//
//        case (COMMENT_CMD):
//            rtn_val = error_free;
//            break;
//        case (NONE_CMD):
//            rtn_val = error;
//            break;
//        default:
//            assert(false);
//            break;
//    };
//    return (rtn_val);
//}
//
//static errorType OnInit(void** DS, const char* const command) {
//    if (isInit) {
//        printf("init was already called.\n");
//        return (error_free);
//    };
//    isInit = true;
//
//    ValidateRead(0, 0, "%s failed.\n", commandStr[INIT_CMD]);
//    *DS = Init();
//
//    if (*DS == NULL) {
//        printf("init failed.\n");
//        return error;
//    };
//
//    printf("init done.\n");
//    return error_free;
//}
//
//static errorType OnAddCourse(void* DS, const char* const command) {
//    int courseID, numOfClasses;
//    ValidateRead(sscanf(command, "%d %d", &courseID, &numOfClasses), 2, "%s failed.\n", commandStr[ADDCOURSE_CMD]);
//    StatusType res = AddCourse(DS, courseID, numOfClasses);
//
//    if (res != SUCCESS) {
//        printf("%s: %s\n", commandStr[ADDCOURSE_CMD], ReturnValToStr(res));
//        return error_free;
//    }
//
//    printf("%s: %s\n", commandStr[ADDCOURSE_CMD], ReturnValToStr(res));
//    return error_free;
//}
//
//static errorType OnRemoveCourse(void* DS, const char* const command) {
//    int courseID;
//    ValidateRead(sscanf(command, "%d", &courseID), 1, "%s failed.\n", commandStr[REMOVECOURSE_CMD]);
//    StatusType res = RemoveCourse(DS, courseID);
//
//    if (res != SUCCESS) {
//        printf("%s: %s\n", commandStr[REMOVECOURSE_CMD], ReturnValToStr(res));
//        return error_free;
//    }
//
//    printf("%s: %s\n", commandStr[REMOVECOURSE_CMD], ReturnValToStr(res));
//    return error_free;
//}
//
//static errorType OnWatchClass(void* DS, const char* const command) {
//    int courseID, classID, time;
//    ValidateRead(sscanf(command, "%d %d %d", &courseID, &classID, &time), 3, "%s failed.\n", commandStr[WATCHCLASS_CMD]);
//    StatusType res = WatchClass(DS, courseID, classID, time);
//
//    if (res != SUCCESS) {
//        printf("%s: %s\n", commandStr[WATCHCLASS_CMD], ReturnValToStr(res));
//        return error_free;
//    }
//
//    printf("%s: %s\n", commandStr[WATCHCLASS_CMD], ReturnValToStr(res));
//    return error_free;
//}
//
//static errorType OnTimeViewed(void* DS, const char* const command) {
//    int courseID, classID, timeViewed;
//    ValidateRead(sscanf(command, "%d %d", &courseID, &classID), 2, "%s failed.\n", commandStr[TIMEVIEWED_CMD]);
//    StatusType res = TimeViewed(DS, courseID, classID, &timeViewed);
//
//    if (res != SUCCESS) {
//        printf("%s: %s\n", commandStr[TIMEVIEWED_CMD], ReturnValToStr(res));
//        return error_free;
//    }
//
//    printf("%s: %d\n", commandStr[TIMEVIEWED_CMD], timeViewed);
//    return error_free;
//}
//
//static errorType OnGetMostViewedClasses(void* DS, const char* const command) {
//    int numOfClasses;
//    int *courses = NULL, *classes = NULL;
//    StatusType res;
//
//    ValidateRead(sscanf(command, "%d", &numOfClasses), 1, "%s failed.\n", commandStr[GETMOSTVIEWEDCLASSES_CMD]);
//    if (numOfClasses > 0) {
//        courses = (int *)malloc(numOfClasses * sizeof(int));
//        classes = (int *)malloc(numOfClasses * sizeof(int));
//        if (courses == NULL || classes == NULL) {
//            res = ALLOCATION_ERROR;
//        }
//    }
//
//    if (res != ALLOCATION_ERROR) {
//        res = GetMostViewedClasses(DS, numOfClasses, courses, classes);
//    }
//
//    if (res != SUCCESS) {
//        printf("%s: %s\n", commandStr[GETMOSTVIEWEDCLASSES_CMD], ReturnValToStr(res));
//        if (courses != NULL) free(courses);
//        if (classes != NULL) free(classes);
//        return error_free;
//    }
//
//    printf("%s: %s\n", commandStr[GETMOSTVIEWEDCLASSES_CMD], ReturnValToStr(res));
//
//    printf("Course\t|\tClass\n");
//
//    for (int i = 0; i < numOfClasses; i++)
//    {
//        printf("%d\t|\t%d\n", courses[i], classes[i]);
//    }
//
//    printf("--End of most viewed classes--\n");
//
//    if (courses != NULL) free(courses);
//    if (classes != NULL) free(classes);
//
//    return error_free;
//}
//
//static errorType OnQuit(void** DS, const char* const command) {
//    Quit(DS);
//    if (*DS != NULL) {
//        printf("quit failed.\n");
//        return error;
//    };
//
//    isInit = false;
//    printf("quit done.\n");
//    return error_free;
//}

#ifdef __cplusplus
}
#endif