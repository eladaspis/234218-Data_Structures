//
// Created by Elad on 05/12/2020.
//

#ifndef HW1_WET_BOOM_H
#define HW1_WET_BOOM_H


#include "AVLTree.h"
#include "library.h"

class Lecture{
    int id;
public:
    Lecture(int id);
    friend ostream& operator<<(ostream& os,const Lecture& lecture){
        os << "Lecture number: " << lecture.id;
        return os;
    }
    ~Lecture();
};

class Course{                                                         //Course
    int id;
    AVLTree<int, Lecture>* lectures;
public:
    Course(int id);
    Course(int id, AVLTree<int, Lecture>* lectures);
    friend ostream& operator<<(ostream& os,const Course& course){
        os << endl << "Course id " << course.id <<endl;
        os << *course.lectures <<endl;
        return os;
    }
    StatusType add_lecture(int id);
    AVLTree<int, Lecture>* course_get_tree();
    StatusType remove_lecture(int id);
    ~Course();

};

class NodeList {
    int key;
    AVLTree<int, Course>* tree_courses;
    NodeList* next_node;
    NodeList* prev_node;

public:
    NodeList(int key);
    ~NodeList();
    StatusType insert_course(int id);
    StatusType insert_course_with_lectures(int id, AVLTree<int, Lecture>* lecture);
    StatusType remove_course_from_node(int id);
    NodeList* insert_before(int new_time , int classID , int courseID,bool flag);
    StatusType remove_node_from_list(NodeList*& last);
    void print_get_most(int& count);
    NodeList* get_next();
    void set_next(NodeList* next);
    NodeList* get_prev();
    void set_prev(NodeList* prev);
    void display();
    int get_key();
    AVLTree<int, Course>* nodeList_get_tree();
};

class List{
    NodeList* first;
    NodeList* last;
public:
    List();
    ~List();
    friend ostream& operator<<(ostream& os,const List& list){
        NodeList* tmp = list.first;
        while(tmp!= nullptr){
            os << "Time: " << tmp->get_key() <<endl;
            os << *tmp->nodeList_get_tree() << endl;
            tmp = tmp->get_next();
        }
        return os;
    }
    NodeList* get_first();
    NodeList* get_last();
    NodeList* insert_before(NodeList* node_list ,int new_time , int classID , int CourseID);
};



class lecturesOfCourse{
    int courseID;                                      //lecture_Of_Course
    int numOfClasses;
    NodeList** arr;


public:
    lecturesOfCourse(int numOfClasses,int courseID);
    //lecturesOfCourse& operator=(const lecturesOfCourse& lectures_of_course);
    void set_arr(NodeList* node_list);
    StatusType add_course(int id, int time);
    StatusType remove_course(int id);
    ~lecturesOfCourse();
    NodeList* get_node_from_list(int index);
    int get_num_of_classes();
    NodeList** get_arr();
    void set_node_in_list(int class_id, NodeList* node_list);
    friend ostream& operator<<(ostream& os, const lecturesOfCourse& lecturesOfCourse1){
        os << lecturesOfCourse1.courseID;
        return os;
    }


};

class Boom{                                               //Boom
    AVLTree<int, lecturesOfCourse>* main_tree;
    List* priority_list;
public:
    Boom();
    ~Boom();
    StatusType AddCourse (int courseID, int numOfClasses);
    StatusType RemoveCourse( int courseID);
    StatusType TimeViewed(int courseID, int classID, int* timeViewed);
    StatusType WatchClass(int courseID, int classID, int time);
//    static void print_lectures(Node<int, Lecture>* current_lecture, int* count_lectures,int course_id, int* courses, int* classes, int num_of_classes);
//    static void print_get_most(Node<int, Course>* current_course, int* count_lectures, int* courses, int* classes, int num_of_classes);
    StatusType GetMostViewedClasses(int numOfClasses, int *courses, int *classes);
    lecturesOfCourse* get_course_by_id(int id);
    friend ostream& operator<<(ostream& os,const Boom& boom){
        os << *boom.main_tree <<endl;
        os << *boom.priority_list;
        return os;
    }
    void Quit();
};




#endif //HW1_WET_BOOM_H
