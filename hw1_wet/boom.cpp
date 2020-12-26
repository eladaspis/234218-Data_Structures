//
// Created by Elad on 05/12/2020.
//

#include "boom.h"

Lecture::Lecture(int id) : id(id){}
Lecture::~Lecture() {}

Course::Course(int id): id(id){
    this->lectures = new AVLTree<int, Lecture>();
}

Course::Course(int id, AVLTree<int, Lecture>* lectures): id(id){
    this->lectures = lectures; //need to check !!!!
}
StatusType Course::add_lecture(int id){                   //add_lecture

    if(id<0){
        return INVALID_INPUT;
    }
    Lecture* current_lecture = this->lectures->find(id);
    if(current_lecture == nullptr){                               // if there isn't lecture in the lectures tree (by id)
        Lecture* new_lecture = new Lecture(id);
        this->lectures->insert(id, new_lecture);
        delete new_lecture;
    }
    return SUCCESS;
}

AVLTree<int, Lecture>* Course::course_get_tree(){
    return this->lectures;
}

StatusType Course::remove_lecture(int id){                   //add_lecture
    if(id<0){
        return INVALID_INPUT;
    }
    this->lectures->remove(id);
    return SUCCESS;
}
Course::~Course(){
    if(this!= nullptr){
        if(this->lectures!= nullptr){
            delete this->lectures;
        }
        this->lectures = nullptr;
    }
}


NodeList::NodeList(int key) :key(key), tree_courses(nullptr), next_node(nullptr), prev_node(nullptr){
    this->tree_courses = new AVLTree<int, Course>();
}

NodeList::~NodeList(){
    if(this!= nullptr) {
        if (this->tree_courses != nullptr) {
            delete this->tree_courses;
        }
    }
}
StatusType NodeList::insert_course_with_lectures(int id, AVLTree<int, Lecture>* lecture) {
    if(this == nullptr){
        return FAILURE;
    }
    Course* new_course = new Course(id, lecture);
    this->tree_courses->insert(id, new_course);
    return SUCCESS;
}
StatusType NodeList::remove_course_from_node(int id){
    if(this==nullptr){
        return INVALID_INPUT;
    }
    this->tree_courses->remove(id);
    return SUCCESS;
}

StatusType NodeList::remove_node_from_list(NodeList*& last){
//    if(this->next_node== nullptr){
//        *last = this->prev_node;
//    }
    if(this->next_node != nullptr && this->prev_node != nullptr){
        this->next_node->prev_node = this->prev_node;
        this->prev_node->next_node = this->next_node;
        delete this;
    }
    else if(this->prev_node != nullptr){
        this->prev_node->next_node = nullptr;
        NodeList* tmp = this->prev_node;
        delete this;
        last = tmp;
    }
    return SUCCESS;
}

NodeList* NodeList::get_next(){
    return this->next_node;
}

void NodeList::set_next(NodeList* next){
    this->next_node = next;
}
NodeList* NodeList::get_prev(){
    return prev_node;
}
void NodeList::set_prev(NodeList* prev){
    this->prev_node = prev;
}
int NodeList::get_key(){
    return this->key;
}
void NodeList::display(){
    if(this !=nullptr){
        cout << "key: " << key << "value: " << tree_courses << endl;
        this->next_node->display();
    }
}
AVLTree<int, Course>* NodeList::nodeList_get_tree(){
    return this->tree_courses;
}


NodeList* NodeList::insert_before(int new_time , int classID , int courseID, bool flag){  //insert_before
    NodeList* new_node = new NodeList(new_time);
    if(flag == true){

        new_node -> prev_node = this;
        this->next_node = new_node;
    }
    else{
        new_node->next_node = this;
        new_node->prev_node = this->prev_node;
        this->prev_node->next_node = new_node;
        this->prev_node = new_node;  
    }

    //create lecture_tree
    AVLTree<int,Lecture>* lecture_tree = new AVLTree<int,Lecture>();
    Lecture* new_lecture = new Lecture(classID);
    lecture_tree->insert(classID , new_lecture);
    delete new_lecture;
    new_node->insert_course_with_lectures(courseID , lecture_tree);
    return new_node;
}


List::List(): first(nullptr), last(nullptr){                          //List Ct'r
    NodeList* new_node = new NodeList(0);
    first = new_node;
    last = new_node;
}
List::~List(){
    while(this->first!= nullptr){
        NodeList* tmp = this->first;
        this->first = this->first->get_next();
        if(tmp!= nullptr){
            delete tmp;
            tmp= nullptr;
        }
    }
}

NodeList* List::get_first(){
    return this->first;
}
NodeList* List::get_last(){
    return this->last;
}

NodeList* List::insert_before(NodeList* node_list ,int new_time , int classID , int CourseID){
    NodeList* return_value = node_list;
    bool flag = false;
    NodeList* tmp2= nullptr;
    while(node_list !=nullptr && new_time > node_list->get_key() ){
        node_list = node_list->get_next();
    }
    if(node_list == nullptr){                             //node_list == nullptr (need to insert in last)
        flag = true;
        NodeList* tmp  = this->last->insert_before(new_time ,classID , CourseID , flag);
        this->last = tmp;
        if(return_value->nodeList_get_tree()->is_empty() && return_value->get_key()!=0){
            return_value->remove_node_from_list(this->last);
        }
        return tmp;
    }
    else{
        if(new_time < node_list->get_key()){ //insert before node
            tmp2 = node_list->insert_before(new_time , classID , CourseID, flag);
        }
        if(new_time == node_list->get_key()){  //insert in current node
            Course* new_course = node_list->nodeList_get_tree()->find(CourseID);
            if(new_course!=nullptr){                   // course exist
                new_course->add_lecture(classID);
            }
            else{                                                            //course not exist in tree
                AVLTree<int, Lecture>* new_lectures_tree = new AVLTree<int, Lecture>();
                Lecture* new_lecture = new Lecture(classID);
                new_lectures_tree->insert(classID, new_lecture);
                delete new_lecture;
                node_list->insert_course_with_lectures(CourseID, new_lectures_tree);
            }
            tmp2=node_list;
        }
    }

    if(return_value->nodeList_get_tree()->is_empty() && return_value->get_key()!=0){
        return_value->remove_node_from_list(this->last);
    }

    return tmp2;
}



lecturesOfCourse::lecturesOfCourse(int courseID, int numOfClasses) : courseID(courseID), numOfClasses(numOfClasses), arr(new NodeList*[numOfClasses]){    //not complete
//    arr = new NodeList*[numOfClasses];

}

void lecturesOfCourse::set_arr(NodeList* node_list){
    for (int i = 0; i < this->numOfClasses; ++i) {
        this->arr[i] = node_list;
    }
}

NodeList* lecturesOfCourse::get_node_from_list(int index){
    return this->arr[index];
}

lecturesOfCourse::~lecturesOfCourse(){
    if(arr!= nullptr){
        delete[] this->arr;
        this->arr = nullptr;
    }
}


int lecturesOfCourse::get_num_of_classes(){
    return this->numOfClasses;
}

NodeList** lecturesOfCourse::get_arr(){
    return this->arr;
}

void lecturesOfCourse::set_node_in_list(int class_id, NodeList* node_list){
    this->arr[class_id] = node_list;
}




Boom::Boom() : main_tree(new AVLTree<int, lecturesOfCourse>()), priority_list(new List()) {                        //Boom Ct'r
}
Boom::~Boom(){
    if(this->main_tree!= nullptr){
        delete main_tree;
        main_tree=nullptr;
    }
    if(this->priority_list!= nullptr){
        delete priority_list;
        priority_list=nullptr;
    }
}
StatusType Boom::AddCourse (int courseID, int numOfClasses){                  //AddCourse
    if(this == nullptr || numOfClasses<=0 || courseID <= 0){   //check input validity
        return INVALID_INPUT;
    }
    if(this->main_tree->find(courseID) != nullptr){   //course with this id already exist
        return FAILURE;
    }
    else{
        lecturesOfCourse* new_lecture_of_course = new lecturesOfCourse(courseID,numOfClasses);
        if(new_lecture_of_course == nullptr){
            return ALLOCATION_ERROR;
        }
        AVLTree<int, Lecture>* lecture_tree = new AVLTree<int, Lecture>(); //check bad_alloc
        for(int i=0;i<numOfClasses;i++){
            Lecture* lecture = new Lecture(i);
            lecture_tree->insert(i,lecture); //add lecture to lecture tree in course object
        }
        new_lecture_of_course->set_arr(this->priority_list->get_first());

        this->main_tree->insert(courseID , new_lecture_of_course); //add lecture_of_course to the main tree

        StatusType res = this->priority_list->get_first()->insert_course_with_lectures(courseID , lecture_tree); //add course with all it lectures to nodeList
        if(res == FAILURE) return FAILURE;
        return SUCCESS;
    }
}
StatusType Boom::RemoveCourse( int courseID){
    if(this == nullptr || courseID <= 0){
        return INVALID_INPUT;
    }
    lecturesOfCourse* lecture_of_course = this->main_tree->find(courseID);
    if(lecture_of_course == nullptr){ //if not exist in tree
        return FAILURE;
    }
    for(int i=0 ; i<lecture_of_course->get_num_of_classes() ;i++) {
        if(lecture_of_course->get_arr()!= nullptr){
            Course* course = lecture_of_course->get_arr()[i]->nodeList_get_tree()->find(courseID);
            course->remove_lecture(i);
            if(course->course_get_tree()->is_empty()){ //Courses is empty
                lecture_of_course->get_arr()[i]->nodeList_get_tree()->remove(courseID);
            }
            if(lecture_of_course->get_arr()[i]->nodeList_get_tree()->is_empty() && lecture_of_course->get_arr()[i]->get_key()!=0){ //Node is empty
                NodeList* temp = this->priority_list->get_last();
                lecture_of_course->get_arr()[i]->remove_node_from_list(temp);
            }
            lecture_of_course->get_arr()[i] = nullptr;
//            lecture_of_course->get_arr()[i]->remove_course_from_node(courseID);
//            if(lecture_of_course->get_arr()[i]->nodeList_get_tree()->is_empty() && lecture_of_course->get_arr()[i]->get_key()!=0){
//                NodeList* tmp = lecture_of_course->get_arr()[i];
//                lecture_of_course->get_arr()[i] = nullptr;
//                tmp->remove_node_from_list((NodeList**)this->priority_list->get_last());
//            }
        }
    }
    this->main_tree->remove(courseID);
    return SUCCESS;
//
//    if(this == nullptr || courseID <= 0){
//        return INVALID_INPUT;
//    }
//    if(this->main_tree->find(courseID) == nullptr){ //if not exist in tree
//        return FAILURE;
//    }
//    for(int i=0 ; i<this->main_tree->find(courseID)->get_num_of_classes() ;i++) {
//        if(this->main_tree->find(courseID)->get_arr()!= nullptr){
//            this->main_tree->find(courseID)->get_arr()[i]->nodeList_get_tree()->find(courseID)->remove_lecture(i);
//            if(this->main_tree->find(courseID)->get_arr()[i]->nodeList_get_tree()->find(courseID)->course_get_tree()->is_empty()){ //Courses is empty
//                this->main_tree->find(courseID)->get_arr()[i]->nodeList_get_tree()->remove(courseID);
//                //course->course_get_tree()->remove(courseID);
//            }
//            if(this->main_tree->find(courseID)->get_arr()[i]->nodeList_get_tree()->is_empty() && this->main_tree->find(courseID)->get_arr()[i]->get_key()!=0){ //Node is empty
//                NodeList* temp = this->priority_list->get_last();
//                this->main_tree->find(courseID)->get_arr()[i]->remove_node_from_list(temp);
//                if(this->main_tree->find(courseID)->get_arr()[i]->get_next() != nullptr && this->main_tree->find(courseID)->get_arr()[i]->get_prev() != nullptr){
//                    this->main_tree->find(courseID)->get_arr()[i]->get_next()->set_prev(this->main_tree->find(courseID)->get_arr()[i]->get_prev());
//                    this->main_tree->find(courseID)->get_arr()[i]->get_prev()->set_next(this->main_tree->find(courseID)->get_arr()[i]->get_next());
//                    delete this;
//                }
//                else if(this->main_tree->find(courseID)->get_arr()[i]->get_prev() != nullptr){
//                    this->main_tree->find(courseID)->get_arr()[i]->get_prev()->set_next(nullptr);
//                    NodeList* tmp = this->main_tree->find(courseID)->get_arr()[i]->get_prev();
//                    delete this->main_tree->find(courseID)->get_arr()[i];
//                    temp = tmp;
//                }
//
//
//            }
//            this->main_tree->find(courseID)->get_arr()[i] = nullptr;
////            lecture_of_course->get_arr()[i]->remove_course_from_node(courseID);
////            if(lecture_of_course->get_arr()[i]->nodeList_get_tree()->is_empty() && lecture_of_course->get_arr()[i]->get_key()!=0){
////                NodeList* tmp = lecture_of_course->get_arr()[i];
////                lecture_of_course->get_arr()[i] = nullptr;
////                tmp->remove_node_from_list((NodeList**)this->priority_list->get_last());
////            }
//        }
//    }
//    this->main_tree->remove(courseID);
//    return SUCCESS;



}



StatusType Boom::WatchClass( int courseID, int classID, int time) {                // Boom WatchClass

    if (this == nullptr) {
        return INVALID_INPUT;
    }
    lecturesOfCourse *new_lecture_of_course = this->main_tree->find(courseID);
    if (new_lecture_of_course == nullptr) {
        return FAILURE;
    }
    int numOfClasses = new_lecture_of_course->get_num_of_classes();
    if (time <= 0 || classID < 0 || courseID <= 0 || classID + 1 > numOfClasses) {
        return INVALID_INPUT;
    }
    NodeList *new_node_list = new_lecture_of_course->get_node_from_list(classID);
    int current_time = new_node_list->get_key();
    Course *new_course = new_node_list->nodeList_get_tree()->find(courseID);
    new_course->course_get_tree()->remove(classID);            //remove lecture from lecture tree of course
    if(new_course->course_get_tree()->is_empty()){
        new_node_list->nodeList_get_tree()->remove(courseID);
    }
    NodeList *current_node_list = this->priority_list->insert_before(new_node_list, current_time + time, classID,
                                                                     courseID);
    if (current_node_list == nullptr) {
        return FAILURE;
    }
    new_lecture_of_course->set_node_in_list(classID, current_node_list);
    return SUCCESS;
}




StatusType Boom::TimeViewed(int courseID, int classID, int* timeViewed){           // Boom TimeViewed
    if (this == nullptr || courseID<=0 || classID <0){
        return INVALID_INPUT;
    }
    lecturesOfCourse* new_lecture_of_course = this->main_tree->find(courseID);
    if(new_lecture_of_course == nullptr){
        return FAILURE;
    }
    NodeList* new_node = new_lecture_of_course->get_node_from_list(classID);
    *timeViewed = new_node->get_key();
    return SUCCESS;
}
static void print_lectures(Node<int, Lecture>* current_lecture, int* count_lectures,int course_id, int* courses, int* classes, int num_of_classes){
    if(current_lecture == nullptr || *count_lectures >= num_of_classes) return;
    if(current_lecture->node_get_left()!=nullptr){
        print_lectures(current_lecture->node_get_left(), count_lectures, course_id, courses, classes, num_of_classes);
    }
    if(*count_lectures >= num_of_classes) return;
    courses[*count_lectures] = course_id;
    classes[*count_lectures] = current_lecture->node_get_key();
    *count_lectures = *count_lectures + 1;
    if(current_lecture->node_get_right()!=nullptr){
        print_lectures(current_lecture->node_get_right(), count_lectures, course_id, courses, classes, num_of_classes);
    }
}
static void print_get_most(Node<int, Course>* current_course, int* count_lectures, int* courses, int* classes, int num_of_classes){
    if(current_course == nullptr || *count_lectures >= num_of_classes) return;
    if(current_course->node_get_left()!=nullptr){
        print_get_most(current_course->node_get_left(), count_lectures, courses, classes, num_of_classes);
    }
    print_lectures(current_course->node_get_value()->course_get_tree()->get_root(),
                     count_lectures, current_course->node_get_key(), courses, classes, num_of_classes);
    if(current_course->node_get_right()!=nullptr){
        print_get_most(current_course->node_get_right(), count_lectures, courses, classes, num_of_classes);
    }
}


StatusType Boom::GetMostViewedClasses(int numOfClasses, int *courses, int *classes){
    if(this== nullptr || numOfClasses<=0){
        return INVALID_INPUT;
    }
    NodeList* tmp= this->priority_list->get_last();
    int count=0;
    while(tmp!= nullptr && count<numOfClasses){
        Node<int, Course>* ptr_course = tmp->nodeList_get_tree()->get_smallest_node();
//        int height = tmp->nodeList_get_tree()->avl_get_height()+1;
//        if(numOfClasses<height) {
        for (int i = 0; i < numOfClasses && ptr_course->node_get_parent()!= nullptr; i++) {
            ptr_course = ptr_course->node_get_parent();
        }
        print_get_most(ptr_course, &count, courses, classes, numOfClasses);
//        }
//        else{
//            int current_steps=0;
//            for (int i = 0; i < numOfClasses && ptr_course->node_get_parent()!= nullptr; i++) {
//                ptr_course = ptr_course->node_get_parent();
//                current_steps++;
//            }
//            numOfClasses=numOfClasses-current_steps;
//            print_get_most(ptr_course, &count, courses, classes, numOfClasses);
//        }
        tmp = tmp->get_prev();
    }
    return SUCCESS;
}
void Boom::Quit(){
    delete this;
}

