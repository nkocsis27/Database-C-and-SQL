//
// Project 4
//


//Part 1 Question 1 using appendix A

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
typedef struct SNAP_TUPLE *TUPLELIST_SNAP;
struct SNAP_TUPLE {
    int StudentId; //KEY //if the student id is -1, this means that the key is not existent and need to search through
    char* Name;
    char* Address;
    char* Phone;
    TUPLELIST_SNAP next;
};
typedef TUPLELIST_SNAP HASHTABLE1[1009];
HASHTABLE1 hash1;

//allocating memory for each tuple and creates the tuple
TUPLELIST_SNAP new_snapTuple(int ID,char* Name,char* Address,char* Phone) {
    struct SNAP_TUPLE* st = (struct SNAP_TUPLE*)malloc(sizeof(struct SNAP_TUPLE));
    //malloc for every single string
    st->Phone = (char*) malloc(9*sizeof(char));
    st->Address = (char*) malloc(20*sizeof(char));
    st->Name = (char*) malloc(20*sizeof(char));
    st->next = (TUPLELIST_SNAP)malloc(sizeof(TUPLELIST_SNAP));
    st->next = NULL;
    st->StudentId = ID;
    st->Name = Name;
    st->Address = Address;
    st->Phone = Phone;
    return st;
}
//function to free the TUPLELIST SNAP
void free_SNAP(TUPLELIST_SNAP t)
{
    free(t->Phone);
    free(t->Address);
    free(t->Name);
    free(t->next);
    free(t);
}


typedef struct CSG_TUPLE *TUPLELIST_CSG;
struct CSG_TUPLE {
    char* Course; //KEY
    int StudentId; //KEY
    char* Grade;
    TUPLELIST_CSG next;
};
typedef TUPLELIST_CSG HASHTABLE2[1009];
HASHTABLE2 hash2;

//allocating memory for each tuple and creates the tuple
TUPLELIST_CSG new_CSGTuple(int ID,char* course,char* grade) {
    struct CSG_TUPLE *st = (struct CSG_TUPLE*)malloc(sizeof(struct CSG_TUPLE));
    //malloc for every single string
    st->Course = (char*) malloc(10*sizeof(char));
    st->Grade = (char*) malloc(3*sizeof(char));
    st->next = (TUPLELIST_CSG)malloc(sizeof(TUPLELIST_CSG));
    st->next = NULL;
    st->StudentId = ID;
    st->Course = course;
    st->Grade = grade;
    return st;
}

//frees tuples
void free_CSG(TUPLELIST_CSG t)
{
    free(t->Course);
    free(t->Grade);
    free(t->next);
    free(t);
}

typedef struct CP_TUPLE *TUPLELIST_CP;
struct CP_TUPLE{
    char* Course; //KEY
    char* Prereq;
    TUPLELIST_CP next;
};
typedef TUPLELIST_CP HASHTABLE3[1009];
HASHTABLE3 hash3;

//allocating memory for each tuple and creates the tuple
TUPLELIST_CP new_CPTuple(char* course, char* prereq) {
    struct CP_TUPLE *st = (struct CP_TUPLE*)malloc(sizeof(struct CP_TUPLE));
    //malloc for every single string
    st->Course = (char*) malloc(7*sizeof(char));
    st->Prereq = (char*) malloc(7*sizeof(char));
    st->next = (TUPLELIST_CP)malloc(sizeof(TUPLELIST_CP));
    st->next = NULL;
    st->Course = course;
    st->Prereq = prereq;
    return st;
}

//frees tuple
void free_CP(TUPLELIST_CP t)
{
    free(t->Course);
    free(t->Prereq);
    free(t->next);
    free(t);
}


typedef struct CDH_TUPLE *TUPLELIST_CDH;
struct CDH_TUPLE{
    char* Course; //KEY
    char* Day;
    int Hour;
    TUPLELIST_CDH next;
};
typedef TUPLELIST_CDH HASHTABLE4[1009];
HASHTABLE4 hash4;

//allocating memory for each tuple and creates the tuple
TUPLELIST_CDH new_CDHTuple(char* course, char* day, int hour)
{
    struct CDH_TUPLE *st = (struct CDH_TUPLE*)malloc(sizeof(struct CDH_TUPLE));
    st->Course = (char*)malloc(10*sizeof(char));
    st->Day = (char*) malloc(2*sizeof(char));
    st->next = (TUPLELIST_CDH)malloc(sizeof(TUPLELIST_CDH));
    st->next = NULL;
    st->Hour = hour;
    st->Course = course;
    st->Day = day;
    return st;
}

//frees tuple
void free_CDH(TUPLELIST_CDH t)
{
    free(t->next);
    free(t->Day);
    free(t->Course);
    free(t);
}

typedef struct CR_TUPLE *TUPLELIST_CR;
struct CR_TUPLE{
    char* Course; //KEY
    char* Room;
    TUPLELIST_CR next;
};
typedef TUPLELIST_CR HASHTABLE5[1009];
HASHTABLE5 hash5;

//allocating memory for each tuple and creates the tuple
TUPLELIST_CR new_CRTuple(char* course, char* room)
{
    struct CR_TUPLE *st = (struct CR_TUPLE*)malloc(sizeof(struct CR_TUPLE));
    //malloc for every single string
    st->Course = (char*) malloc(10*sizeof(char));
    st->Room = (char*) malloc(20*sizeof(char));
    st->next = (TUPLELIST_CR)malloc(sizeof(TUPLELIST_CR));
    st->next = NULL;
    st->Course = course;
    st->Room = room;
    return st;
}

//frees tuple
void free_CR(TUPLELIST_CR t)
{
    free(t->next);
    free(t->Room);
    free(t->Course);
    free(t);
}


//returns bucket index using the string key and/or number key
int bucketIndex(char* string, int num) {
    int value = 0;
    //hash value
    if (strcmp(string, "CSC252") == 0)
    {
        value+=10;
    }
    if (strcmp(string, "CSC254") == 0)
    {
        value+=20;
    }
    for (int i = 0; i < strlen(string); i++) {
        value = value + string[i];
    }
    return (num+value) % 1009;
}


//printing functions (for the individual tuples and the entire table)
void print_SNAP(TUPLELIST_SNAP tuple)
{
    printf("<%d , ", tuple->StudentId);
    printf(" %s,", tuple->Name);
    printf(" %s,", tuple->Address);
    printf(" %s", tuple->Phone);
    printf("> ");
}

//prints snap table
void printtable_SNAP()
{
    //iterating through the hashtable
    for (int i = 0; i < 1009; i++)
    {
        TUPLELIST_SNAP tup = hash1[i];
        if (tup != NULL) {
            printf("\n");
        }
        while (tup != NULL)
        {
            print_SNAP(tup);
            tup = tup->next;
        }
    }
}

//prints CDH tuple
void print_CDH(TUPLELIST_CDH t)
{
    printf("<%s,", t->Course);
    printf(" %s,", t->Day);
    printf(" %d", t->Hour);
    printf("> ");
}

//prints CDH tuple
void printtable_CDH()
{
    //iterating through the hashtable
    for (int i = 0; i < 1009; i++)
    {
        TUPLELIST_CDH tup = hash4[i];
        if (tup != NULL) {
            printf("\n");
        }
        while (tup != NULL)
        {
            print_CDH(tup);
            tup = tup->next;
        }
    }
}

//prints CSG tuple
void print_CSG(TUPLELIST_CSG tuple)
{
    printf("<%s ,", tuple->Course);
    printf(" %d,", tuple->StudentId);
    printf(" %s ", tuple->Grade);
    printf("> ");
}

//prints CSG table
void printtable_CSG()
{
    //iterating through the hashtable
    for (int i = 0; i < 1009; i++)
    {
        TUPLELIST_CSG tup = hash2[i];
        if (tup != NULL) {
            printf("\n");
        }
        while (tup != NULL)
        {
            // !!! is this line supposed to be print_CSG ???
            print_CSG(tup);
            tup = tup->next;
        }
    }
}

//prints CP Tuple
void print_CP(TUPLELIST_CP t)
{
    printf("<%s,", t->Course);
    printf(" %s", t->Prereq);
    printf("> ");
}

//prints CP table
void printtable_CP()
{
    for (int i = 0; i < 1009; i++) {
        TUPLELIST_CP tup = hash3[i];
        if (tup != NULL) {
            printf("\n");
        }
        while (tup != NULL) {
            print_CP(tup);
            tup = tup->next;
        }
    }
}

//prints CR tuple
void print_CR(TUPLELIST_CR t)
{
    printf("<%s,", t->Course);
    printf(" %s,", t->Room);
    printf("> ");
}

//prints CR table
void printtable_CR()
{
    for (int i = 0; i < 1009; i++)
    {
        TUPLELIST_CR tup = hash5[i];
        if (tup != NULL) {
            printf("\n");
        }
        while (tup != NULL)
        {
            print_CR(tup);
            tup = tup->next;
        }
    }
}

//inserts SNAP tuple into hash table
void insert_SNAP(int ID, char* Name, char* Address, char* Phone) {
    int index = bucketIndex("",ID);
    int dup = 0;

    if (hash1[index]==NULL)
    {
        hash1[index] = new_snapTuple(ID,Name,Address,Phone);
    }
    else
    {
        //check to see if dups
        //traverse through the end of the linked list
        TUPLELIST_SNAP u = hash1[index];
        while (u != NULL)
        {
            if (u->StudentId == ID && u->Name == Name && u->Address == Address && u->Phone == Phone) {
                dup ++;
                u = u->next;

            } else {
                u = u->next;
            }
        }
        //now once we've reached the end insert the tuple
        if(dup == 0) {
            hash1[index]->next = new_snapTuple(ID,Name,Address,Phone);
        }
    }

}

//deletes SNAP from hash table
void delete_SNAP(int ID, char* n, char* a, char* p)
{
    if (ID == -1) { //this means that the key doesn't exist
        for (int i = 0; i < 1009; i++) {
            if (hash1[i] != NULL) { //if bucket isn't empty
                TUPLELIST_SNAP u = hash1[i];
                TUPLELIST_SNAP prev = NULL;
                while (u != NULL) {
                    if (((strcmp(n,u->Name) == 0) || strcmp(n,"*") == 0) && ((strcmp(u->Address, a) == 0)||  strcmp(a, "*") == 0)
                        && (u->Phone == p || strcmp(p,"*") == 0)) { //have match
                        TUPLELIST_SNAP delete = u;
                        if (prev == NULL) {
                            if (u->next == NULL) {
                                //if only one tuple is in bucket
                                delete = NULL;
                                u = NULL;
                                hash1[i] = delete;
                                free(delete);
                                //just delete
                            } else {
                                //if tuple is first element but has a next
                                delete = NULL;
                                free(delete);
                                u = u->next;
                                hash1[i] = u;
                            }
                        } else {
                            if (u->next == NULL) {
                                //last element in tuple
                                delete = NULL;
                                prev->next = NULL;
                                free(delete);
                                u = u->next;
                                //just delete
                            } else {
                                //tuple is in middle somewhere
                                prev->next = delete->next;
                                delete = NULL;
                                free(delete);
                                u = u->next;
                            }
                        }
                    } else {
                        prev = u;
                        u = u->next;
                    }
                }
            }
        }
    }
    else //if the id does exist, only look through the bucket for a given int id
    {
        int index = bucketIndex("", ID);
        if(hash1[index] != NULL) {
            TUPLELIST_SNAP u = hash1[index];
            TUPLELIST_SNAP prev = NULL;
            while (u != NULL) {
                if ((strcmp(n,u->Name) == 0 || strcmp(n,"*") == 0) && (strcmp(u->Address, a) == 0 ||  strcmp(a, "*") == 0) && (u->Phone == p || (strcmp(p, "*") == 0) )) { //have match
                    TUPLELIST_SNAP delete = u;
                    if (prev == NULL) {
                        if (u->next == NULL) {
                            //if only one tuple is in bucket
                            delete = NULL;
                            u = NULL;
                            hash1[index] = delete;
                            free(delete);

                            //just delete
                        } else {
                            //if tuple is first element but has a next
                            delete = NULL;
                            free(delete);
                            u = u->next;
                            hash1[index] = u;
                        }
                    } else {
                        if (u->next == NULL) {
                            //last element in tuple
                            delete = NULL;
                            prev->next = delete;
                            free(delete);
                            u = u->next;
                            //just delete
                        } else {
                            //tuple is in middle somewhere
                            prev->next = delete->next;
                            delete = NULL;
                            free(delete);
                            u = u->next;

                        }
                    }
                } else {
                    prev = u;
                    u = u->next;
                }
            }
        }
    }
}

//looks up if SNAP is in table and prints tuple if there
void lookup_SNAP(int ID, char* n, char* a, char* p) {
    int found = 0;
    if (ID == -1) { //this means that the key doesn't exist
        for (int i = 0; i < 1009; i++) //iterate through the entire hash table
        {
            if (hash1[i] != NULL) {
                TUPLELIST_SNAP u = hash1[i];
                while (u != NULL) {
                    if (((strcmp(u->Name, n)) == 0 || strcmp(n, "*") == 0) && ((strcmp(u->Address, a)) == 0 || strcmp(a, "*") == 0) &&
                        ((strcmp(u->Phone, p) == 0) || (strcmp(p, "*") == 0))) {
                        printf("tuple: found");
                        found = 1;
                        print_SNAP(u);
                    }
                    u = u->next;
                }
                //now we are finished looking at one bucket of the hashtable
            }
        }
    } else //if the id does exist, only look through the bucket for a given int id
    {
        int index = bucketIndex("", ID);
        TUPLELIST_SNAP u = hash1[index];
        while (u != NULL)
        {
            if ((ID == u->StudentId || ID == -1)&&((strcmp(u->Name, n)) == 0 || strcmp(n, "*") == 0) && ((strcmp(u->Address, a)) == 0 ||
                                                                                                         strcmp(a, "*") == 0) && ((strcmp(u->Phone, p) == 0) || (strcmp(p, "*") == 0)))
            {
                printf("tuple found: ");
                found = 1;
                print_SNAP(u);
            }
            u = u->next;
        }
    }
    if(found == 0) {
        printf("Lookup: tuple does not exist.");
    }
}

//insert CSG tuple into CSG hash table
void insert_CSG(int idnum, char* course, char* grade)
{
    //note that we are hashing hash2 on the student id and the course
    int index = bucketIndex(course, idnum);
    int dup = 0;
    if (hash2[index] == NULL) {
        hash2[index] = new_CSGTuple(idnum,course,grade);
    }
    else {
        TUPLELIST_CSG u = hash2[index];
        while (u != NULL)
        {
            if (strcmp(u->Course, course) == 0 && strcmp(u->Grade, grade) == 0 && idnum == u->StudentId) {
                dup ++;
                u = u->next;

            } else {
                u = u->next;
            }
        }

        //now once we've reached the end insert the tuple
        if(dup == 0)
        {
            hash2[index]->next = new_CSGTuple(idnum, course, grade);
        }
    }
}

//delete function for CSG
void delete_CSG(int idnum, char* c, char* g)
{
    if ((strcmp(c, "*") == 0) || idnum == -1 ) {//index isn't given iterate through whole hashtable
        for (int i = 0; i < 1009; i++) {
            if (hash2[i] != NULL) { //if bucket isn't empty
                TUPLELIST_CSG u = hash2[i];
                TUPLELIST_CSG prev = NULL;
                while (u != NULL) {
                    if (((strcmp(c,u->Course) == 0) || strcmp(c,"*") == 0) && ((strcmp(u->Grade, g) == 0)||  strcmp(g, "*") == 0)
                        && (u->StudentId == idnum|| idnum == -1 )) { //have match
                        TUPLELIST_CSG delete = u;
                        if (prev == NULL) {
                            if (u->next == NULL) {
                                //if only one tuple is in bucket
                                delete = NULL;
                                u = NULL;
                                hash2[i] = delete;
                                free(delete);
                                //just delete
                            } else {
                                //if tuple is first element but has a next
                                delete = NULL;
                                free(delete);
                                u = u->next;
                                hash2[i] = u;
                            }
                        } else {
                            if (u->next == NULL) {
                                //last element in tuple
                                delete = NULL;
                                prev->next = NULL;
                                free(delete);
                                u = u->next;
                                //just delete
                            } else {
                                //tuple is in middle somewhere
                                prev->next = delete->next;
                                delete = NULL;
                                free(delete);
                                u = u->next;
                            }
                        }
                    } else {
                        prev = u;
                        u = u->next;
                    }
                }
            }
        }
    } else {
        //have key
        int index = bucketIndex(c, idnum);
        if(hash2[index] != NULL) {
            TUPLELIST_CSG u = hash2[index];
            TUPLELIST_CSG prev = NULL;
            while (u != NULL) {
                if ((strcmp(c,u->Course) == 0 || strcmp(c,"*") == 0) && (strcmp(u->Grade, g) == 0 ||  strcmp(g, "*") == 0)
                    && (u->StudentId == idnum|| idnum == -1 )) { //have match
                    TUPLELIST_CSG delete = u;
                    if (prev == NULL) {
                        if (u->next == NULL) {
                            //if only one tuple is in bucket
                            delete = NULL;
                            u = NULL;
                            hash2[index] = delete;
                            free(delete);
                            //just delete
                        } else {
                            //if tuple is first element but has a next
                            delete = NULL;
                            free(delete);
                            u = u->next;
                            hash2[index] = u;
                        }
                    } else {
                        if (u->next == NULL) {
                            //last element in tuple
                            delete = NULL;
                            prev->next = delete;
                            free(delete);
                            u = u->next;
                            //just delete
                        } else {
                            //tuple is in middle somewhere
                            prev->next = delete->next;
                            delete = NULL;
                            free(delete);
                            u = u->next;
                        }
                    }
                } else {
                    prev = u;
                    u = u->next;
                }
            }
        }
    }
}

//lookup function for CSG and prints if there
void lookup_CSG(int id, char* c, char* g)
{
    int found = 0;
    //note that course is the key for CDH relation
    if ((strcmp(c, "*") == 0) || id == -1 ) { //this means that the key doesn't exist
        for (int i = 0; i < 1009; i++) //iterate through the entire hash table
        {
            if (hash2[i] != NULL) {
                TUPLELIST_CSG u = hash2[i];
                while (u != NULL) {
                    if ((strcmp(u->Course, c) == 0 || strcmp(c, "*") == 0) &&
                        ((u->StudentId == id) || id == -1) && (strcmp(u->Grade, g) == 0 || strcmp(g,"*") == 0 )) {
                        printf("tuple found: ");
                        found = 1;
                        print_CSG(u);
                    }
                    u = u->next;
                }
                //now we are finished looking at one bucket of the hashtable
            }
        }
    } else //if the id does exist, only look through the bucket for a given int id
    {
        int index = bucketIndex(c, id);
        TUPLELIST_CSG u = hash2[index];
        while (u != NULL)
        {
            if ((strcmp(u->Course, c) == 0)&&(u->StudentId == id)&&((strcmp(u->Grade, g) == 0 || strcmp(g,"*") == 0 )))
            {
                printf("tuple found: ");
                found = 1;
                print_CSG(u);
            }
            u = u->next;
        }
    }
    if(found == 0) {
        printf("Lookup: tuple does not exist.");
    }
}

//insert function for CP
void insert_CP(char* course, char* prereq)
{
    int index = bucketIndex(course, 0);
    int dup = 0;
    if(hash3[index] == NULL)
    {
        hash3[index] = new_CPTuple(course, prereq);
    }
    else
    {
        TUPLELIST_CP u = hash3[index];
        while (u != NULL)
        {
            if (strcmp(u->Course, course) == 0 && strcmp(u->Prereq, prereq) == 0) {
                dup = 1;
                u = u->next;
            } else {
                u = u->next;
            }
        }
        //now once we've reached the end insert the tuple
        if (dup == 0)
            hash3[index]->next = new_CPTuple(course, prereq);
    }
}

//delete function for CP
void delete_CP(char* c, char* p)
{
    //note that the key for this problem is the course and we are dealing with hash3
    if (strcmp(c,"*") == 0) {//index isn't given iterate through whole hashtable
        for (int i = 0; i < 1009; i++) {
            if (hash3[i] != NULL) { //if bucket isn't empty
                TUPLELIST_CP u = hash3[i];
                TUPLELIST_CP prev = NULL;
                while (u != NULL) {
                    if ((strcmp(p,u->Prereq) == 0 || strcmp(p,"*") == 0)) { //have match
                        TUPLELIST_CP delete = u;
                        if (prev == NULL) {
                            if (u->next == NULL) {
                                //if only one tuple is in bucket
                                delete = NULL;
                                u = NULL;
                                hash3[i] = delete;
                                free(delete);
                                //just delete
                            } else {
                                //if tuple is first element but has a next
                                delete = NULL;
                                free(delete);
                                u = u->next;
                                hash3[i] = u;
                            }
                        } else {
                            if (u->next == NULL) {
                                //last element in tuple
                                delete = NULL;
                                prev->next = NULL;
                                free(delete);
                                u = u->next;
                                //just delete
                            } else {
                                //tuple is in middle somewhere
                                prev->next = delete->next;
                                delete = NULL;
                                free(delete);
                                u = u->next;

                            }
                        }
                    } else {
                        prev = u;
                        u = u->next;
                    }
                }
            }
        }
    } else {
        //have key
        int index = bucketIndex(c, 0);
        if(hash3[index] != NULL) {
            TUPLELIST_CP u = hash3[index];
            print_CP(u);
            TUPLELIST_CP prev = NULL;
            while (u != NULL) {
                if ((strcmp(u->Course, c) == 0)&&(strcmp(u->Prereq, p) == 0 || strcmp(p,"*") == 0)) { //have match
                    TUPLELIST_CP delete = u;
                    if (prev == NULL) {
                        if (u->next == NULL) {
                            //if only one tuple is in bucket
                            delete = NULL;
                            u = NULL;
                            hash3[index] = delete;
                            free(delete);
                            //just delete
                        } else {
                            //if tuple is first element but has a next
                            delete = NULL;
                            free(delete);
                            u = u->next;
                            hash3[index] = u;
                        }
                    } else {
                        if (u->next == NULL) {
                            //last element in tuple
                            delete = NULL;
                            prev->next = delete;
                            free(delete);
                            u = u->next;
                            //just delete
                        } else {
                            //tuple is in middle somewhere
                            prev->next = delete->next;
                            delete = NULL;
                            free(delete);
                            u = u->next;
                        }
                    }
                } else {
                    prev = u;
                    u = u->next;
                }
            }
        }
    }
}

//lookup function for CP and prints if there
void lookup_CP(char* c, char* p)
{
    int found = 0;
    //note that course is the key for CP relation
    if (strcmp(c,"*") == 0) { //this means that the key doesn't exist
        for (int i = 0; i < 1009; i++) //iterate through the entire hash table
        {
            if (hash3[i] != NULL) {
                TUPLELIST_CP u = hash3[i];
                while (u != NULL) {
                    if ((strcmp(u->Prereq, p) == 0 || strcmp(p, "*") == 0)) {
                        printf("tuple found: ");
                        found = 1;
                        print_CP(u);
                    }
                    u = u->next;
                }
                //now we are finished looking at one bucket of the hashtable
            }
        }
    }
    else //if the id does exist, only look through the bucket for a given int id
    {
        int index = bucketIndex(c, 0);
        TUPLELIST_CP u = hash3[index];
        while (u != NULL)
        {
            if ((strcmp(u->Course, c) == 0)&&((strcmp(u->Prereq, p)) == 0 || strcmp(p, "*") == 0))
            {
                printf("tuple found: ");
                found = 1;
                print_CP(u);
            }
            u = u->next;
        }
    }
    if(found == 0) {
        printf("Lookup: tuple does not exist");
    }
}

//insert function for CDH
void insert_CDH(char* course, char* day, int h)
{
    //note that we are hashing hash2 on the student id and the course
    int index = bucketIndex(course,0);
    int dup = 0;
    if (hash4[index]==NULL)
    {
        hash4[index] = new_CDHTuple(course, day, h);
    }
    else
    {
        //check to see if dups
        //traverse through the end of the linked list
        TUPLELIST_CDH u = hash4[index];
        while (u != NULL)
        {
            if (strcmp(u->Course, course) == 0 && strcmp(u->Day, day) == 0 && u->Hour == h) {
                dup = 1;
                u = u->next;
            } else {
                u = u->next;
            }
        }
        //now once we've reached the end insert the tuple
        if (dup == 0)
            hash4[index]->next = new_CDHTuple(course, day, h);
    }
}

//delete function for CDH
void delete_CDH(char* c, char* d, int h)
{
    //note that the key for this problem is the course and we are dealing with hash4
    if (strcmp(c,"*") == 0) {//index isn't given iterate through whole hashtable
        for (int i = 0; i < 1009; i++) {
            if (hash4[i] != NULL) { //if bucket isn't empty
                TUPLELIST_CDH u = hash4[i];
                TUPLELIST_CDH prev = NULL;
                while (u != NULL) {
                    if ((strcmp(d,u->Day) == 0 || strcmp(d,"*") == 0) && ((u->Hour == h) || h == -1)) { //have match
                        TUPLELIST_CDH delete = u;
                        if (prev == NULL) {
                            if (u->next == NULL) {
                                //if only one tuple is in bucket
                                delete = NULL;
                                u = NULL;
                                hash4[i] = delete;
                                free(delete);
                                //just delete
                            } else {
                                //if tuple is first element but has a next
                                delete = NULL;
                                free(delete);
                                u = u->next;
                                hash4[i] = u;
                            }
                        } else {
                            if (u->next == NULL) {
                                //last element in tuple
                                delete = NULL;
                                prev->next = NULL;
                                free(delete);
                                u = u->next;
                                //just delete
                            } else {
                                //tuple is in middle somewhere
                                prev->next = delete->next;
                                delete = NULL;
                                free(delete);
                                u = u->next;
                            }
                        }
                    } else {
                        prev = u;
                        u = u->next;
                    }
                }
            }
        }
    } else {
        //have key
        int index = bucketIndex(c, 0);
        if(hash4[index] != NULL) {
            TUPLELIST_CDH u = hash4[index];
            print_CDH(u);
            TUPLELIST_CDH prev = NULL;
            while (u != NULL) {
                if ((strcmp(u->Course, c) == 0)&&(strcmp(u->Day, d) == 0 || strcmp(d,"*") == 0) && (u->Hour == h|| h == -1)) { //have match
                    TUPLELIST_CDH delete = u;
                    if (prev == NULL) {
                        if (u->next == NULL) {
                            //if only one tuple is in bucket
                            delete = NULL;
                            u = NULL;
                            hash4[index] = delete;
                            free(delete);
                            //just delete
                        } else {
                            //if tuple is first element but has a next
                            delete = NULL;
                            free(delete);
                            u = u->next;
                            hash4[index] = u;
                        }
                    } else {
                        if (u->next == NULL) {
                            //last element in tuple
                            delete = NULL;
                            prev->next = delete;
                            free(delete);
                            u = u->next;
                            //just delete
                        } else {
                            //tuple is in middle somewhere
                            prev->next = delete->next;
                            delete = NULL;
                            free(delete);
                            u = u->next;
                        }
                    }
                } else {
                    prev = u;
                    u = u->next;
                }
            }
        }
    }
}

//lookup function for CDH and prints if there
void lookup_CDH(char* c, char* d, int h)
{
    int found = 0;
    //note that course is the key for CDH relation
    if (strcmp(c,"*") == 0) { //this means that the key doesn't exist
        for (int i = 0; i < 1009; i++) //iterate through the entire hash table
        {
            if (hash4[i] != NULL) {
                TUPLELIST_CDH u = hash4[i];
                while (u != NULL) {
                    if ((strcmp(u->Day, d) == 0 || strcmp(d, "*") == 0) && ((u->Hour == h) || h == -1)) {
                        printf("tuple found: ");
                        found = 1;
                        print_CDH(u);
                    }
                    u = u->next;
                }
                //now we are finished looking at one bucket of the hashtable
            }
        }
    } else //if the id does exist, only look through the bucket for a given int id
    {
        int index = bucketIndex(c, 0);
        TUPLELIST_CDH u = hash4[index];
        while (u != NULL)
        {
            if ((strcmp(u->Course, c) == 0)&&((strcmp(u->Day, d)) == 0 || strcmp(d, "*") == 0)
                && (u->Hour == h|| h == -1))
            {

                printf("tuple found: ");
                found = 1;
                print_CDH(u);
            }
            u = u->next;
        }
    }
    if(found == 0) {
        printf("Lookup: tuple does not exist.");
    }
}

//insert for CR
void insert_CR(char* c, char* Location) {
    int index = bucketIndex(c, 0);
    int dup = 0;
    if (hash5[index] == NULL) {
        hash5[index] = new_CRTuple(c,Location);
    } else {
        TUPLELIST_CR u = hash5[index];
        while (u != NULL)
        {
            if (strcmp(u->Course, c) == 0 && strcmp(u->Room, Location) == 0) {
                dup ++;
                u = u->next;

            } else {
                u = u->next;
            }
        }

        //now once we've reached the end insert the tuple
        if(dup == 0) {
            hash5[index]->next = new_CRTuple(c,Location);
        }
    }
}

//delete for CR
void delete_CR(char* c, char* r) {
    if (strcmp(c,"*") == 0) {//index isn't given iterate through whole hashtable
        for (int i = 0; i < 1009; i++) {
            if (hash5[i] != NULL) { //if bucket isn't empty
                TUPLELIST_CR u = hash5[i];
                TUPLELIST_CR prev = NULL;
                while (u != NULL) {
                    if ((strcmp(r,u->Room) == 0 || strcmp(r,"*") == 0) && ((strcmp(c,u->Course)==0) || strcmp(c,"*") == 0)) { //have match
                        TUPLELIST_CR delete = u;
                        if (prev == NULL) {
                            if (u->next == NULL) {
                                //if only one tuple is in bucket
                                delete = NULL;
                                u = NULL;
                                hash5[i] = delete;
                                free(delete);
                                //just delete
                            } else {
                                //if tuple is first element but has a next
                                delete = NULL;
                                free(delete);
                                u = u->next;
                                hash5[i] = u;
                            }
                        } else {
                            if (u->next == NULL) {
                                //last element in tuple
                                delete = NULL;
                                prev->next = NULL;
                                free(delete);
                                u = u->next;
                                //just delete
                            } else {
                                //tuple is in middle somewhere
                                prev->next = delete->next;
                                delete = NULL;
                                free(delete);
                                u = u->next;

                            }
                        }
                    } else {
                        prev = u;
                        u = u->next;
                    }

                }
            }
        }
    } else {
        //have key
        int index = bucketIndex(c, 0);
        if(hash5[index] != NULL) {
            TUPLELIST_CR u = hash5[index];
            TUPLELIST_CR prev = NULL;
            while (u != NULL) {
                if ((strcmp(r,u->Room) == 0 || strcmp(r,"*") == 0) && ((strcmp(c,u->Course) == 0) || strcmp(c,"*") == 0)) { //have match
                    TUPLELIST_CR delete = u;
                    if (prev == NULL) {
                        if (u->next == NULL) {
                            //if only one tuple is in bucket
                            delete = NULL;
                            u = NULL;
                            hash5[index] = delete;
                            free(delete);
                            //just delete
                        } else {
                            //if tuple is first element but has a next
                            delete = NULL;
                            free(delete);
                            u = u->next;
                            hash5[index] = u;
                        }
                    } else {
                        if (u->next == NULL) {
                            //last element in tuple
                            delete = NULL;
                            prev->next = delete;
                            free(delete);
                            u = u->next;
                            //just delete
                        } else {
                            //tuple is in middle somewhere
                            prev->next = delete->next;
                            delete = NULL;
                            free(delete);
                            u = u->next;
                        }
                    }
                } else {
                    prev = u;
                    u = u->next;
                }
            }
        }
    }
}

//lookup function for CR and prints if there
void lookup_CR(char* c, char* r)
{
    int found = 0;
    //note that course is the key for CP relation
    if (strcmp(c,"*") == 0) { //this means that the key doesn't exist
        for (int i = 0; i < 1009; i++) //iterate through the entire hash table
        {
            if (hash5[i] != NULL) {
                TUPLELIST_CR u = hash5[i];
                while (u != NULL) {
                    if ((strcmp(u->Room, r) == 0 || strcmp(r, "*") == 0)) {
                        printf("tuple found: ");
                        found = 1;
                        print_CR(u);
                    }
                    u = u->next;
                }
                //now we are finished looking at one bucket of the hashtable
            }
        }
    }
    else //if the id does exist, only look through the bucket for a given int id
    {
        int index = bucketIndex(c, 0);
        TUPLELIST_CR u = hash5[index];
        while (u != NULL)
        {
            if ((strcmp(u->Course, c) == 0)&&((strcmp(u->Room, r)) == 0 || strcmp(r, "*") == 0))
            {
                printf("tuple found: ");
                found = 1;
                print_CR(u);
            }
            u = u->next;
        }
    }
    if(found == 0) {
        printf("Lookup: tuple does not exist.");
    }
}

//PART 2

//planning for what grade did a student get in a course?
//step 1: look at CSG table (hash 2) and find the student ID for a given course and grade from user
//step 2: with that student id, look at the SNAP table (hash 1) , hash it to look in correct bucket and find the
//name of the student (user the s->name thing)
//print the name
//then ask the user to continue putting in input or to stop

//returns student ID given name, and -1 if name is not in hashtable
int lookup_STUDENTID(char* n)
{
    for (int i = 0; i < 1009; i++) //iterate through the entire hash table
    {
        if (hash1[i] != NULL) {
            TUPLELIST_SNAP u = hash1[i];
            while (u != NULL) {
                if ((strcmp(u->Name, n)) == 0){
                    return u->StudentId;
                }
                u = u->next;
            }
            //now we are finished looking at one bucket of the hashtable
        }
    }
    return -1;
}

//returns letter grade given student ID and course and NULL if not found
char* lookup_findGrade(int idnum, char* course)
{
    //first hash
    int index = bucketIndex(course, idnum);
    TUPLELIST_CSG u = hash2[index];
    while (u != NULL) {
        if ((strcmp(u->Course, course)) == 0 && u->StudentId == idnum){
            return u->Grade;
        }
        u = u->next;
    }
    return NULL;
}

//Gets user input for first query
void repl_gradeofstudent()
{
    char name[25];
    char course[10];
    int valid = 1;
    while(valid == 1)
    {
        printf("\nEnter a student name (type quit to quit) : \n");
        scanf("%[^\n]%*c", name);
        int value1 = strcmp(name,"quit");
        if (value1 == 0)
        {
            break;
        }
        printf("\nEnter the course (type quit to quit) : \n");
        scanf("%[^\n]%*c", course);
        int value2 = strcmp(course,"quit");
        if (value2 == 0)
        {
            break;
        }
        int idnum = lookup_STUDENTID(name);
        if (idnum == -1)
        {
            printf("Student is not found.\n");
        }
        else
        {
            char* grade = lookup_findGrade(idnum, course);
            if (grade == NULL)
            {
                printf("Student does not take course.");
            }
            else
            {
                printf("Grade of student %s in the course %s is %s.\n", name, course,grade);
            }
        }
        //now we have the id num so as long as it's not null, find the course from hash 2 associated to it
        valid = 1;

    }
}

//returns room location given Student ID number, hour, and day.
char* findroom(int idnum, int h, char* day)
{
    //go through the CSG bucket for given student id and find the courses of the student
    //every time you find a course, you go through the CDH database, try to find a course that matches for the
    // specific day and hour
    //if you find a relation that matches the course, day and hour, use that course and the CR relation to find the
    //room it's in and return that room
    for (int i = 0 ; i < 1009; i++)
    {
        //the key for CSG is on course and student id so need to iterate through the entire hashtable
        if (hash2[i] != NULL) {
            TUPLELIST_CSG tup = hash2[i];
            while (tup != NULL) {
                if (tup->StudentId == idnum) {
                    char *course = tup->Course;
                    //found a course for the student, now need to iterate through CDH to find
                    //if there is a tuple for that course given on that day and hour
                    int indexofcourse = bucketIndex(course, 0);
                    //search through the entire bucket for the course

                    TUPLELIST_CDH u = hash4[indexofcourse];
                    if (u != NULL) {
                        while (u != NULL) {
                            //checking the values
                            if ((strcmp(u->Course, course) == 0) && (strcmp(u->Day, day) == 0) && u->Hour == h) {
                                //it has found a tuple for a given COURSE for day and hour
                                //look to find the location of the room with the CR relation
                                int indexofcforroom = bucketIndex(course, 0);
                                TUPLELIST_CR cr = hash5[indexofcforroom];
                                if (cr != NULL) {
                                    while (cr != NULL) {
                                        if (strcmp(cr->Course, course) == 0) {
                                            return cr->Room;
                                        }
                                        cr = cr->next;
                                    }
                                }
                            }
                            u = u->next;
                        }
                    }
                }
                tup = tup->next;
            }
        }
    }
    //if nothing was returned from the method, default return value is NULL
    return NULL;
}


//where is name at hour on day? (looking for the location of the room)
//Step 1 -> use SNAP (hash 1) to find the id number of the name
//Step 2--> use the CSG (hash 2) to find all the classes the student is in
//Step 3--> use the CDH (hash 4) table (hash to figure out the class that is correct for the given HOUR and DAY
//Step 4 --> use the CR table to figure out the room for the given class, then print that out

//gets user input for Query
void repl_location()
{
    char name[25];
    char day[4];
    char hour[6];

    int valid = 1;
    while(valid == 1)
    {
        printf("\nEnter a student name (type quit to quit) : \n");
        scanf("%[^\n]%*c", name);
        int value1 = strcmp(name,"quit");
        if (value1 == 0)
        {
            break;
        }
        printf("\nEnter the day (type quit to quit) : \n");
        scanf("%[^\n]%*c", day);
        int value2 = strcmp(day,"quit");
        if (value2 == 0) {
            break;
        }

        char* d = malloc(sizeof(day));
        d = day;

        printf("\nEnter the hour (type quit to quit) : \n");
        scanf("%[^\n]%*c", hour);
        int value3 = strcmp(hour,"quit");
        if (value3 == 0)
        {
            break;
        }
        int idnum = lookup_STUDENTID(name);

        if (idnum == -1)
        {
            printf("Student is not found.\n");
        }
        else
        {
            int h = atoi(hour);
            //the hour h value is correct

            //we have student id so run CSG to find all the classes the student is in
            char* room = findroom(idnum, h, d);
            if (room == NULL)
            {
                printf("Room is NOT FOUND for given day and hour.\n");
            }
            else
            {
                printf("\nThe room where the student %s is on the day %s and hour %s is %s.\n", name, day, hour, room);
            }

        }
        valid = 1;
    }

}


// part 3

typedef struct HOURANDDAY *DH;
struct HOURANDDAY{
    int hour;
    char* day;
    DH next;
};

DH new_DH(char* day, int h)
{
    struct HOURANDDAY *st = (struct HOURANDDAY *)malloc(sizeof(DH));
    st->hour = h;
    st->day = (char*)malloc(2*sizeof(char));
    st->day = day;
    st->next = (DH)malloc(sizeof(DH));
    st->next = NULL;
    return st;
}

void print_DH(DH tuple)
{
    printf("<%s ,", tuple->day);
    printf(" %d", tuple->hour);
    printf("> ");
}

//join CR and CDH for natural join
typedef struct COURSEROOMDAYHOUR *TUPLELIST_CRDH;
struct COURSEROOMDAYHOUR
{
    int hour;
    char* day;
    char* room;
    char* course;
    TUPLELIST_CRDH next;
};
typedef TUPLELIST_CRDH HASHTABLE6[1009];
HASHTABLE6 hash6;

TUPLELIST_CRDH new_CRDH(char* course, char* r, char* day, int hour)
{
    struct COURSEROOMDAYHOUR *st = (struct COURSEROOMDAYHOUR *)malloc(sizeof(TUPLELIST_CRDH));
    st->hour = hour;
    st->course = (char*) malloc(10*sizeof(char));
    st->course = course;
    st->day = (char*)malloc(2*sizeof(char));
    st->day = day;
    st->room = (char*) malloc(20*sizeof(char));
    st->room = r;
    st->next = (TUPLELIST_CRDH)malloc(sizeof(TUPLELIST_CRDH));
    st->next = NULL;
    return st;
}

void print_CRDH(TUPLELIST_CRDH tuple)
{
    printf("<%s ,", tuple->course);
    printf(" %s,", tuple->room);
    printf(" %s, ", tuple->day);
    printf(" %d", tuple->hour);
    printf("> ");
}

//prints CRDH table
void printtable_CRDH()
{
    //iterating through the hashtable
    for (int i = 0; i < 1009; i++)
    {
        TUPLELIST_CRDH tup = hash6[i];
        if (tup != NULL) {
            printf("\n");
        }
        while (tup != NULL)
        {
            print_CRDH(tup);
            tup = tup->next;
        }
    }
}

// for C
typedef struct COURSE *C;
struct COURSE{
    char* course;
    C next;
};


C new_C(char* c)
{
    struct COURSE *st = (struct COURSE*)malloc(sizeof(C));
    st->course = (char*) malloc(10*sizeof(char));
    st->course = c;
    st->next = (C)malloc(sizeof(C));
    st->next = NULL;
    return st;
}

void print_C(C tuple)
{
    printf("<%s", tuple->course);
    printf("> ");
}





//insert function for CRDH
void insert_CRDH(char* course, char* room, char* day, int hour)
{
    int index = bucketIndex(course, 0);
    int dup = 0;
    if(hash6[index] == NULL)
    {
        hash6[index] = new_CRDH(course, room, day, hour);

    }
    else
    {
        TUPLELIST_CRDH u = hash6[index];
        while (u != NULL)
        {
            if (strcmp(u->course, course) == 0 && strcmp(u->room, room) == 0 && strcmp(u->day, day) == 0 && (u->hour == hour)) {
                dup = 1;
                u = u->next;
            } else {
                u = u->next;
            }
        }
        //now once we've reached the end insert the tuple
        if (dup == 0)
            hash6[index]->next = new_CRDH(course, room, day, hour);
    }
}

TUPLELIST_CRDH CRDH_select_room(char* room) {
    TUPLELIST_CRDH temp = NULL;
    for (int i = 0; i < 1009; i++) {
        if (hash6[i] != NULL) {
            TUPLELIST_CRDH u = hash6[i];
            while (u != NULL) {
                if (strcmp(u->room, room) == 0) {
                    if (temp == NULL) {

                        temp = new_CRDH(u->course, u->room, u->day, u->hour);
                    } else {

                        TUPLELIST_CRDH l = temp;
                        while (l->next != NULL) {
                            l = l->next;
                        }
                        l->next = new_CRDH(u->course, u->room, u->day, u->hour);
                    }
                }

                u = u->next;
            }
        }
    }
    if (temp == NULL) {
        printf("NULL\n");
    }
    return temp;
}

TUPLELIST_CSG CSG_select_ID(int id)
{
    TUPLELIST_CSG temp = NULL;
    for (int i = 0; i < 1009; i++) {
        if (hash2[i] != NULL) {
            TUPLELIST_CSG u = hash2[i];
            while (u != NULL) {
                if (u->StudentId == id) {
                    if (temp == NULL) {
                        temp = new_CSGTuple(u->StudentId, u->Course, u->Grade);
                    } else {
                        TUPLELIST_CSG l = temp;
                        while (l->next != NULL) {
                            l = l->next;
                        }
                        l->next = new_CSGTuple(u->StudentId, u->Course, u->Grade);
                    }
                }
                u = u->next;
            }
        }
    }
    return temp;
}

//this function will return all the courses, given the selection on an id
C project_course_CSG(int id) {
    C C_TUPLE = NULL;
    //this function will return a linked list with all CSG tuples with the given id inputs
    TUPLELIST_CSG CSG_select_tuplist = CSG_select_ID(id);
    while (CSG_select_tuplist != NULL) {
        if (C_TUPLE == NULL) {
            C_TUPLE = new_C(CSG_select_tuplist->Course);
        } else {
            C l = C_TUPLE;
            while (l->next != NULL) {
                l = l->next;
            }
            l->next = new_C(CSG_select_tuplist->Course);
        }
        CSG_select_tuplist = CSG_select_tuplist->next;
    }
    return C_TUPLE;
}

//join
void CRDH_join()
{
    //joining on course
    for(int i = 0; i < 1009; i ++) {
        if(hash5[i] != NULL) {
            TUPLELIST_CR u = hash5[i]; //note that the course stuff does not have multiple rooms
            while(u != NULL) {
                //HASHTABLE4 h = lookup_CDH(u->Course, "*", -1);
                for(int r = 0; r < 1009; r ++) {
                    if(hash4[r] != NULL) {
                        TUPLELIST_CDH u2 = hash4[r];
                        while(u2 != NULL) {
                            if(strcmp(u->Course, u2->Course) == 0)
                            {
                                insert_CRDH(u->Course, u->Room, u2->Day, u2->Hour);
                            }
                            u2 = u2->next;
                        }
                    }
                }
                u = u->next;
                /*int j = 0;
                while (h[j] != NULL) {
                    //assuming that there is only one thing in each bucket
                    TUPLELIST_CDH tup = h[j];
                    insert_CRDH(u->Course, u->Room, tup->Day, tup->Hour);
                    j ++;
                }
                u = u->next;*/
            }
        }
    }
}

DH project_day_hour_CRDH(char* room) {
    DH temp = NULL;
    CRDH_join(); //this is a void method that just modifies hash 6
    TUPLELIST_CRDH tup_CRDH = CRDH_select_room(room);//now we select room given the CRDH hash table 6

    while (tup_CRDH != NULL) {

        if (temp == NULL) {
            temp = new_DH(tup_CRDH->day, tup_CRDH->hour);
        } else {
            DH l = temp;
            if (temp == NULL) {
                temp = new_DH(tup_CRDH->day, tup_CRDH->hour);
            } else {

                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new_DH(tup_CRDH->day, tup_CRDH->hour);
            }

        }
        tup_CRDH = tup_CRDH->next;
    }

    return temp;
}

void addingAll()
{
    insert_SNAP(11111, "M. Subban","1 Exchange Blvd", "555-1212");
    insert_SNAP(12345, "R. Zmolek","2700 B-H Townline Rd", "555-1111");
    insert_SNAP(67890, "P. Tischke","1 Exchange Blvd", "555-1234");
    insert_SNAP(12321, "F. Cedarqvist","80 Lyndon Rd", "555-2222");
    insert_SNAP(98789, "M. Subban","123 Ling Rd", "555-3333");

    insert_CSG(12345,"CSC171","A");
    insert_CSG(67890,"CSC171","B");
    insert_CSG(12345,"MATH150","A");
    insert_CSG(12345,"DSCC201","C");
    insert_CSG(11111,"DSCC201","B+");
    insert_CSG(98789,"CSC172","A-");
    insert_CSG(67890,"MATH150","C+");
    insert_CSG(12321,"CSC173","B+");
    insert_CSG(98789,"CSC173","A");
    insert_CSG(98789,"DSCC201","C");

    insert_CP("CSC172", "CSC171");
    insert_CP("CSC172", "MATH150");
    insert_CP("CSC173", "CSC172");
    insert_CP("CSC252", "CSC172");
    insert_CP("CSC254", "CSC252");
    insert_CP("DSCC201", "CSC171");
    insert_CP("DSCC202", "DSCC201");
    insert_CP("DSCC265", "DSCC262");
    insert_CP("DSCC265", "CSC171");

    insert_CDH("CSC171", "T", 1400);
    insert_CDH("CSC171", "R", 1400);
    insert_CDH("CSC172", "T", 1525);
    insert_CDH("CSC172", "R", 1640);
    insert_CDH("CSC173", "T", 1400);
    insert_CDH("CSC173", "R", 1400);
    insert_CDH("CSC252", "T", 1230);
    insert_CDH("CSC252", "R", 1230);
    insert_CDH("DSCC201", "M", 900);
    insert_CDH("DSCC201", "W", 900);
    insert_CDH("DSCC202", "M", 1650);
    insert_CDH("DSCC202", "W", 1650);
    insert_CDH("DSCC265", "M", 1400);
    insert_CDH("DSCC265", "W", 1650);

    insert_CR("CSC171","Hutchison Hall 141");
    insert_CR("CSC172", "Hutchison Hall 141");
    insert_CR("CSC173","Wegmans Hall 1400");
    insert_CR("CSC252","Wegmans Hall 1400");
    insert_CR("CSC254","Wegmans Hall 1400");
    insert_CR("DSCC201","Bausch and Lomb 1009");
    insert_CR("DSCC202", "Dewey 2162");
    insert_CR("DSCC265", "Wegmans Hall 1400");
    insert_CR("MATH150", "Harkness 115");
}

int main(){

    // part 1
    addingAll();

    printf("Looking up tuple <CSC172, 98789, *> on relation Course-StudentId-Grade: \n");
    lookup_CSG(98789, "CSC172", "*");

    printf("\n\nLooking up tuple <CSC173, CSC172> on relation Course-Prerequisite: \n");
    lookup_CP("CSC173", "CSC172");


    printf("\n\nDeleting tuple <MATH150, *> from relation Course-Room: \n");
    delete_CR("MATH150","*");
    printtable_CR();

    printf("\n\nInserting tuple <CSC280, CSC173> in relation Course-Prerequisite: ");
    insert_CP("CSC280", "CSC173");
    printtable_CP();

    printf("\n\nInserting tuple <DSCC202, DSCC201> in relation Course-Prerequisite: ");
    insert_CP("DSCC202", "DSCC201");
    printtable_CP();


    // part 2
    addingAll();

    printf("\n\nQuery: What grade did Name get in Course?");
    repl_gradeofstudent(); //runs the first query

    printf("\nQuery: Where is Name at Hour on Day");
    repl_location(); //runs the second query


    // part 3
    printf("\nSelecting tuples where Student ID = 67890 in relation Course-Student-Grade: \n");
    TUPLELIST_CSG tup = CSG_select_ID(67890);
    while(tup != NULL) {
        print_CSG(tup);
        tup = tup->next;
    }

    printf("\n\nFrom CSG relation selecting all tuples that contain a Student ID of 67890 then projecting on course.\n");
    C tup2 = project_course_CSG(67890);
    while(tup2 != NULL) {
        print_C(tup2);
        tup2 = tup2->next;
    }

    printf("\n\nMerging the tuples of CR and CDH, matching on course\n");
    CRDH_join();
    printtable_CRDH();

    /*
    printf("\n\nJoining tuples of CR and CDH, then selecting rooms that are Wegmans 1400, finally projecting day and hour of those tuples\n");
    DH t = project_day_hour_CRDH("Wegmans Hall 1400");
    while(t != NULL) {
        print_DH(t);
        t = t->next;
    }
     */
    
    return 0;
}
