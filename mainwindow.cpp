#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Solve Me..!!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

int curr_row=3,curr_column=3,count=0;

//int arr[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int arr[4][4]={1,4,15,7,8,10,2,11,14,3,6,13,12,9,5,16};

void MainWindow::display()
{

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(arr[i][j]==16)
            {
                ui->table->setItem(i,j,new QTableWidgetItem("X"));
            }
            else
            {
                QString value = QString::number(arr[i][j]);
                ui->table->setItem(i,j,new QTableWidgetItem(value));
            }

        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    /*

      1  | 4   | 15 | 7
      8  | 10  | 2  | 11
      14 | 3   | 6  | 13
      12 | 9   | 5  | X

      convert it into below form

      1  | 2  | 3   | 4
      5  | 6  | 7   | 8
      9  | 10 | 11  | 12
      13 | 14 | 15  | X


    */

    display();
    ui->count->setText("0");

    ui->pushButton->setVisible(false);
}


void MainWindow::check_puzzle()
{
    int flag=0;

    for(int row=0;row<4;row++)
    {
        for(int column=0;column<4;column++)
        {
            int value=row*4 + column + 1;

            if(value!=arr[row][column])
            {
                flag=1;
                break;
            }
        }
    }

    if(flag==0)
    {
        ui->verdict->setText("You Win");
    }
    else
    {
         ui->verdict->setText("You Can Do It..!!");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    //Right button

    int temp_row,temp_coln;
    temp_row=curr_row;
    temp_coln=curr_column+1;

    if( temp_row <= 3 && temp_row >= 0 && temp_coln>=0 && temp_coln <=3)
    {
        count++;

        int temp;

        temp=arr[temp_row][temp_coln];
        arr[temp_row][temp_coln]=arr[curr_row][curr_column];
        arr[curr_row][curr_column]=temp;

        QString str = QString::number(count);
        ui->count->setText(str);

        display();
        check_puzzle();
        curr_row=temp_row;
        curr_column=temp_coln;

    }
    else
    {
        ui->verdict->setText("Invalid Move");
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    //Left button
    int temp_row,temp_coln;
    temp_row=curr_row;
    temp_coln=curr_column-1;

    if( temp_row <= 3 && temp_row >= 0 && temp_coln>=0 && temp_coln <=3)
    {
        count++;

        int temp;

        temp=arr[temp_row][temp_coln];
        arr[temp_row][temp_coln]=arr[curr_row][curr_column];
        arr[curr_row][curr_column]=temp;

        QString str = QString::number(count);
        ui->count->setText(str);

        display();
        check_puzzle();

        curr_row=temp_row;
        curr_column=temp_coln;
    }
    else
    {
        ui->verdict->setText("Invalid Move");
    }

    //end


}

void MainWindow::on_pushButton_2_clicked()
{
    //Up button

    int temp_row,temp_coln;
    temp_row=curr_row-1;
    temp_coln=curr_column;

    if( temp_row <= 3 && temp_row >= 0 && temp_coln>=0 && temp_coln <=3)
    {
        count++;

        int temp;

        temp=arr[temp_row][temp_coln];
        arr[temp_row][temp_coln]=arr[curr_row][curr_column];
        arr[curr_row][curr_column]=temp;

        QString str = QString::number(count);
        ui->count->setText(str);

        display();
        check_puzzle();

        curr_row=temp_row;
        curr_column=temp_coln;

    }
    else
    {
        ui->verdict->setText("Invalid Move");
    }


    //end
}

void MainWindow::on_pushButton_5_clicked()
{
    //Down button

    int temp_row,temp_coln;
    temp_row=curr_row+1;
    temp_coln=curr_column;

    if( temp_row <= 3 && temp_row >= 0 && temp_coln>=0 && temp_coln <=3)
    {
        count++;

        int temp;

        temp=arr[temp_row][temp_coln];
        arr[temp_row][temp_coln]=arr[curr_row][curr_column];
        arr[curr_row][curr_column]=temp;

        QString str = QString::number(count);
        ui->count->setText(str);

        display();
        check_puzzle();

        curr_row=temp_row;
        curr_column=temp_coln;

    }
    else
    {
        ui->verdict->setText("Invalid Move");
    }


    //end
}

void MainWindow::on_pushButton_6_clicked()
{

    int brr[16]={1,4,15,7,8,10,2,11,14,3,6,13,12,9,5,16};
    int pos=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            arr[i][j]=brr[pos++];
        }
    }
    count=0;
    curr_row=3;
    curr_column=3;
    ui->count->setText("0");
    display();


}

void MainWindow::on_pushButton_7_clicked()
{
    exit(0);
}
