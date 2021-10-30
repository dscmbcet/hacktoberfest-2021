import java.util.Scanner;

class Queue {
    int temp, temp1, queue[], front, rear, max;
    char ch;
    Scanner sc;

     Queue() {
        this.temp = 0;
        this.temp1 = 0;
        this.front = -1;
        this.rear = -1;
        this.max = 100;
        this.queue = new int[max];
        this.sc = new Scanner(System.in);
    }

    void enqueue() {
        while (true) {
            System.out.println("Enter the element : ");
            temp = sc.nextInt();
            if (rear == max - 1) {
                System.out.println("Queue Overflow \n");
                break;
            } else if (front == 0 && rear == 0) {
                front = rear = -1;
                queue[rear] = temp;
            } else {
                rear++;
                queue[rear] = temp;
            }
            System.out.println("Do you wish to Continue?(y/n) :");
            ch = sc.next().charAt(0);
            if (ch == 'n') {
                break;
            }
        }
    }

    void dequeue() {
        if (front == -1 && rear == -1) {
            System.out.println("Queue UNDERFLOW! \n");
            return;
        }
        System.out.println("Removed element: " + queue[front] + "\n");

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void sortQ() {
        int k, l;
        if (front == -1 && rear == -1) {
            System.out.println("Empty Queue, nothing to sort here! \n");
        } else {
            for (k = 0; k < rear; k++) {
                for (l = 0; l <= rear; l++) {
                    if (queue[l] > queue[l + 1]) {
                        temp1 = queue[l];
                        queue[l+1] = queue[l];
                        queue[l] = temp1;
                    }
                }
            }
        }
    }

    void printQ() {
        int i;
        if (front == -1 && rear == -1) {
            System.out.println("Empty Queue! \n");
        } else {
            System.out.println("Queue :- ");
            for (i = front; i <= rear; i++) {
                System.out.print(" " + queue[i]);
            }
            System.out.println("\n");
        }
    }

}

public class QueueProgram {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Queue q = new Queue();
        int choice;
        while (true) {
            System.out.println(
                    "Enter your choice \n 1:- Enqueue \n 2:- Dequeue \n 3:- Print Queue \n 4:- Sort Queue \n 5:- Exit \n");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    q.enqueue();
                    break;
                case 2:
                    q.dequeue();
                    break;
                case 3:
                    q.printQ();
                    break;
                case 4:
                    q.sortQ();
                    break;
                case 5:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        }
    }
}
