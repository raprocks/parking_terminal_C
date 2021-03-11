// The MIT License (MIT)

// Copyright (c) 2021 Rohit Patil

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ticket
{
    int TicketNumber;
    char vehicle_type;
    int time;
    float fare;
};

void fare_calculate(struct ticket *tick)
{
    // Get the pointer to current struct element in use and modify values directly instead of reassignment.
    tick->fare = (((int)tick->vehicle_type) * tick->time )/100; // calculated fare set directly to fare struct data
}

int main()
{
    struct ticket ts[100]; // array of tickets
    char input; // to take input
    int button = 1; // main switch for do while loop but cant use switch because switch. xD
    // Populate all elements' TicketNumber data in array with Null so as to help find empty structs;
    for (int i = 0; i < 100; i++)
    {
        ts[i].TicketNumber = -1; // direct assignment maybe also assign null values to all other data elements
        // printf("%d| %c| %i | %i\n", ts[i].TicketNumber, ts[i].vehicle_type, ts[i].time, ts[i].vehicle_type);
    }
    // Print Message
    printf("Enter A for Adding a record\n");
    printf("Enter D for Deleting a record\n");
    printf("Enter P to Print all records\n");
    printf("Enter Q to Quit\n");
    printf("Enter H for Help on the Program!\n");
    do
    {
        printf("> ");
        scanf(" %c", &input);
        printf("\n'%c'\n", input);
        switch (input)
        {
        case 'A':
        { // wrapped in curly braces because C thinks struct is a label like `case` and throws error
            // find an ticket with TicketNumber = -1 and populate data with it
            struct ticket *use = NULL;
            use = ts;
            for (int i = 0; i < 100; i++)
            {
                // check all elements to find first empty ticket and break out of the for loop with pointer `use` set to point at the empty ticket element ready to be used
                if (ts[i].TicketNumber == -1)
                {
                    // use = ts[i]; // wanted to directly assign pointer but incrementing is fun hehe
                    break;
                }
                use++; // increment pointer location's address as this location already occupied
                // we are checking like so instead of hash table because if we delete a element with ticketNumber stored in third element and we have populated
                // location 4 ptr will point to 3 first because thats empty instead of going to 5. get it? + easier to implement at such a small level as elements tot travers are low
                // but would definitely use hash table if number of tickets becomes a large number.
            }
            // take data input
            // TickerNumber Assignment auto generated number between 10000 to 99999
            use->TicketNumber = (rand() % (10000 - 99999 + 1)) + 99999;
            // ask vehicle Type
            printf("Enter Vehicle type as (C)ar or (B)ike : ");
            scanf(" %c", &use->vehicle_type); // space in front to ignore the whitespace that scanf doesnt strip when reading `char`
            // use->vehicle_type = type_vehi;
            // printf("%c", use->vehicle_type);
            // ask time
            printf("\nEnter Time in Minutes : ");
            scanf("%i", &use->time);
            // printf("Data Collected");
            // calculate fare and assign it
            // fare(&use);
            // printf("Data Assigned");
            fare_calculate(use); // see definition of function
            break;
        }
        case 'D':
        {
            struct ticket use;
            int ticketNum;
            // ask for TicketNumber
            printf("Provide a TicketNumber to Delete Record of : ");
            scanf(" %d", &ticketNum);
            // find the one with TicketNumber and Delete Number There
            for (int i = 0; i < 100; i++)
            {
                if (ts[i].TicketNumber == ticketNum)
                {
                    ts[i] = (struct ticket){.fare = 0, .TicketNumber = -1, .time = 0, .vehicle_type = 'N'}; // Nullify all data terms
                }
                // Again No Hash Table because size Small will try to implement If size exceeds a big number.
            }
            break;
        }
        case 'P':
        { 
            // Traverse all tickets and print all in tabular manner.
            printf("Printing All Data Now\n");
            for (int i = 0; i < 100; i++)
            {
                if (ts[i].TicketNumber != -1) // If Ticket Number is -1 then the ticket is not used so ignore that
                {
                    printf("%d| %c| %i | %i\n", ts[i].TicketNumber, ts[i].vehicle_type, ts[i].time, ts[i].fare);
                }
            }
            break;
        }
        case 'Q':
        {
            button = 0; // set button to 0 so to exit whle loop
            printf("Quitting the Program Now!\n");
            break;
        }
        case 'H':
        {
            printf("Enter A for Adding a record\n");
            printf("Enter D for Deleting a record\n");
            printf("Enter P to Print all records\n");
            printf("Enter Q to Quit\n");
            break;
        }
        default:
        {
            printf("%c was your input, which isn't valid. Enter H for Help on the Program!\n", input);
            break;
        }
        }
    } while (button);
    return 0;
}
