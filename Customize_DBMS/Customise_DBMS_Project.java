import java.lang.*;
import java.util.*;


class Student   //This class is like a structure from c and c++.
{
    public int RID;
    public String Name;
    public int Age;
    public float Marks;

    private static int Generator; 

    static //This block execute first after creating the object of this class and memory will allocatd.
    {
        Generator = 0;
    }

    public Student(String str, int value,float marks) //Constructor.
    {
        this.RID = ++Generator;
        this.Name = str;
        this.Age = value;
        this.Marks = marks; 
    }

    public void DisplayData()
    {
        System.out.println(this.RID+"\t"+this.Name+"\t"+this.Marks+"\t"+this.Age);
    }
}

class DBMS
{
   public LinkedList <Student> lobj;

    public DBMS()
    {
        lobj = new LinkedList<>();
    }

    public void StartDBMS()
    {
        Scanner scanobj = new Scanner(System.in);

        System.out.println("Customised DBMS started succesfully....");
        String Query = "";

        while(true)
        {
            System.out.print("DBMS console =>");
            Query = scanobj.nextLine();

            String tokens[] = Query.split(" ");
            int QuerySize = tokens.length;

            if(QuerySize == 1)
            {
                if("Help".equals(tokens[0]))
                {
                    System.out.println("This application is used to demonstrates the customised DBMS");
                    System.out.println("Type 'Exit' to terminate DBMS");
                    System.out.println("To display all data enter 'select * from student'");
                    System.out.println("To insert the data type 'Insert into student Name Age Marks'");
                    System.out.println("To check student information by using roll no. type 'Roll No Number'");
                    System.out.println("To check student information by using name type 'Find Name'");
                    System.out.println("To remove the student from list using roll no type 'Remove RollNo'");
                    //System.out.println("To remove the student from list using name type 'Remove Student Name'");
                    System.out.println("To display student having maximum marks type 'Maximum Marks'");
                    System.out.println("To display student having minimum marks type 'Minimum Marks'");
                    System.out.println("To display all student's average marks type 'Average Marks'");
                    System.out.println("To display summation of all marks of all student type 'Sum all Marks'");
                    System.out.println("To count number of student from list type 'Count Students'");
                    
                }
                else if("Exit".equals(tokens[0]))
                {
                    System.out.println("Thank you for using custoised DBMS....");
                    break;
                }
            }
            else if(QuerySize == 2)
            {
                if("Find".equals(tokens[0]))
                {
                    DisplaySpecificString(tokens[1]);
                    /*String str = tokens[1];
                    String name = str.replace("\"", "");
                    DisplaySpecificString(name);*/
                }
                else if("Remove".equals(tokens[0]))
                {
                    DeleteSpecificInt(Integer.parseInt(tokens[1]));
                }
                else if("Maximum".equals(tokens[0]))
                {
                    if("Marks".equals(tokens[1]))
                    {
                        AggregateMax();
                    }
                }
                else if("Minimum".equals(tokens[0]))
                {
                    if("Marks".equals(tokens[1]))
                    {
                        AggregateMin();
                    }
                }
                else if("Average".equals(tokens[0]))
                {
                    if("Marks".equals(tokens[1]))
                    {
                        AggregateAvg();
                    }
                }
                else if("Count".equals(tokens[0]))
                {
                    AggregateCount();
                }
            }
            else if(QuerySize == 3)
            {
                if("Roll".equals(tokens[0]))
                {
                    if("No".equals(tokens[1]))
                    {
                        DisplaySpecificInt(Integer.parseInt(tokens[2]));
                    }
                }
                /*else if("Remove".equals(tokens[0]))
                {
                    if("Student".equals(tokens[1]))
                    {
                        DeleteSpecific(tokens[2]);
                    }
                }*/
                else if("Sum".equals(tokens[0]))
                {
                    if("all".equals(tokens[1]))
                    {
                        AggregateSum();
                    }
                }
            }
            else if(QuerySize == 4)
            {
                if("select".equals(tokens[0]))
                {
                    if("*".equals(tokens[1]))
                    {
                        DisplayAll();
                    }
                }
            }
            else if(QuerySize == 6)
            {
                if("Insert".equals(tokens[0]))
                {
                    InsertData(tokens[3],Integer.parseInt(tokens[4]),Integer.parseInt(tokens[5]));
                }
            }
        }
        scanobj.close();
    }
    //To insert the data.
    public void InsertData(String str, int value,float fValue)
    {
        Student sobj = new Student(str,value,fValue);
        lobj.add(sobj);
    }

    // Display all without condition.
    public void DisplayAll()
    {
        for(Student sref : lobj)
        {
            sref.DisplayData();
        }
    }

    // Display by RID.
    public void DisplaySpecificInt(int rid)
    {
        for(Student sref : lobj)
        {
            if(sref.RID == rid)
            {
                sref.DisplayData();
                break;
            }
        }
    }

    // Display by name.
    public void DisplaySpecificString(String str)
    {
        for(Student sref : lobj)
        {
            if(str.equals(sref.Name))
            {
                sref.DisplayData();
            }
        }
    }

    //Delete by RID
    public void DeleteSpecificInt(int rid)
    {
        int index = 0;

        for(Student sref : lobj)
        {
            if(sref.RID == rid)
            {
                lobj.remove(index);
                break;
            }
            index++;
        }
    }

    //Delete by Name
    public void DeleteSpecific(String str)
    {
        int index = 0;

        for(Student sref : lobj)
        {
            if(str.equals(sref.Name))
            {
                lobj.remove(index);
                break;
            }
            index++;
        }
    }

    //Display Maximum marks.
    public void AggregateMax()
    {
        float iMax = 0;
        Student temp = null;

        for(Student sref : lobj)
        {
            if(sref.Marks > iMax)
            {
                iMax = sref.Marks;
                temp = sref;
            }
        }

        System.out.println("Information of student having maximum marks : ");
        temp.DisplayData();
    }
    //Display Minimum marks.
    public void AggregateMin()
    {
        float iMin = (lobj.getFirst()).Marks;
        Student temp = lobj.getFirst();

        for(Student sref : lobj)
        {
            if(sref.Marks < iMin)
            {
                iMin = sref.Marks;
                temp = sref;
            }
        }
        System.out.println("Information of student having minimum marks : ");
        temp.DisplayData();
    }
    //Display Summation of all marks marks.
    public void AggregateSum()
    {
        float iSum = 0;

        for(Student sref : lobj)
        {
            iSum = iSum + sref.Marks;
        }
        System.out.println("Summation of all marks of all students is : "+ iSum);
    }

    //Display average marks of all students.
    public void AggregateAvg()
    {
        float iSum = 0;

        for(Student sref : lobj)
        {
            iSum = iSum + sref.Marks;
        }
        System.out.println("Average marks of all student is : "+ iSum / (lobj.size()));
    }

    //Display count of all student.
    public void AggregateCount()
    {
        System.out.println("Number of student in school is: "+lobj.size());
    }
}



class Customise_DBMS_Project 
{    public static void main(String arg[])
    {
        DBMS dobj = new DBMS();
        dobj.StartDBMS();
    }
}