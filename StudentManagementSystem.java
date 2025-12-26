import java.util.Scanner;
class Student{
    int rollNo;
    String name;
    int marks;

    void setData(int r, String n, int m){
        rollNo = r;
        name = n;
        marks = m;
    }

    void display(){
        System.out.println(rollNo + "\t" + name + "\t" + marks);
    }
}
public class StudentManagement {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        Student[] students = new Student[5];
        int count = 0;
        int choice;

        do{
            System.out.println("\n---Student Management Menu---");
            System.out.println("1. Add Student");
            System.out.println("2. Display Students");
            System.out.println("3. Search Student");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch(choice){
                case 1:
                    if(count < students.length){
                        students[count] = new Student();

                        System.out.print("Enter Roll No: ");
                        int r = sc.nextInt();

                        System.out.print("Enter Name: ");
                        String n = sc.next();

                        System.out.print("Enter Marks: ");
                        int m = sc.nextInt();

                        students[count].setData(r, n, m);
                        count++;

                        System.out.println("Student added successfully.");
                    }else{
                        System.out.println("Student list if full");
                    }
                    break;

                case 2:
                    System.out.println("\nRoll\tName\tMarks");
                    for(int i=0; i<count; i++){
                        students[i].display();
                    }
                    break;

                case 3:
                    System.out.println("Enter Roll No to search");
                    int searchRoll = sc.nextInt();
                    boolean found = false;

                    for(int i=0; i<count; i++){
                        if(students[i].rollNo == searchRoll){
                            students[i].display();
                            found = true;
                            break;
                        }
                    }

                    if(!found){
                        System.out.println("Student not found");

                    }
                    break;

                case 4:
                    System.out.println("Exiting Program...");
                    break;

                default:
                    System.out.println("Invalid choice.");
            }
        }while(choice != 4);
        sc.close();
    }
}
