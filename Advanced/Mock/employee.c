#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(void)
{
    typedef struct employee {
        char name[14];
        int emp_no;
        char gender;
        float rate, hr;
        struct employee *next;
    } node;

    float pay, total = 0;
    FILE *indata;
    node this1;
    node *temp, *first = NULL;

    indata = fopen("/Users/kemingliu/Desktop/Employ.txt", "r");
    if (indata == NULL) {
        printf("\n wage.inf cannot be found.");
        exit(1);
    }

    printf("\n Employee No. Hours Worked Hourly Rate Wage");
    printf("\n (hr)        ($/hr)       ($)");
    printf("\n ============================================");

    node *ptr;
    while ((fgets(this1.name, 14, indata) != NULL) && (fscanf(indata, "%d %c%f%f%*c", &(this1.emp_no), &(this1.gender), &(this1.rate), &(this1.hr)) == 4)) 
    {
        temp = (node *)malloc(sizeof(node));
        strcpy(temp->name, this1.name);
        temp->emp_no = this1.emp_no;
        temp->gender = this1.gender;
        temp->rate = this1.rate;
        temp->hr = this1.hr;
        
        /*if(first == NULL)
        {
            first = temp;
            temp->next = NULL;
        }

        else if (temp->emp_no < first->emp_no)
        {
            temp->next = first;
            first = temp;
        }*/

        if (first == NULL || temp->emp_no < first->emp_no)
        {
            temp->next = first;
            first = temp;
        }

        
        else
        {
            ptr = first;
            while (ptr->next != NULL &&  ptr->next->emp_no < temp->emp_no)
            {
                ptr = ptr->next;
            }

            temp->next = ptr->next;
            ptr->next = temp;
        }
    }

    temp = first;
    while (temp != NULL) {
        printf("\n %4d        %6.2f     %6.2f ", temp->emp_no, temp->hr, temp->rate);
        if (temp->hr <= 40)
            pay = temp->hr * temp->rate;
        else
            pay = temp->rate * 40 + temp->rate * (temp->hr - 40) * 1.5;
        printf("   %6.2f", pay);
        total += pay;
        temp = temp->next;
    }

    fclose(indata);
    printf("\n\n Total wages = $%-8.2f\n", total);
    return 0;
}
