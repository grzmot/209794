/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Maciej
 */
public class Sala {
    private int row;
    private int space;
    private int number;
    private int number_of_seats;
    private int[][] spaces;
    static int number_of_hall=0;
    
    public Sala() {
        row=0;
        space=0;
        number=0;
        number_of_seats=0;
    }
    public Sala(int row, int space, int number) {
        this.row=row;
        this.space=space;
        number_of_seats=row*space;
        spaces=new int[row][space];
    }
    public Sala(Sala hall) {
        row=hall.row;
	space=hall.space;
	number=hall.number;
	number_of_seats=hall.number_of_seats;
	spaces=new int [row][space];   
    }
    @Override
    protected void finalize() {
        spaces=null;
    }

    public static int get_number_of_hall() {
        return number_of_hall;
    }
    public static void plus_number_of_hall() {
        number_of_hall++;
    }
    public static void minus_number_of_hall() {
        number_of_hall--;
    }
    
    public void set_number(int number) {
        this.number=number;
    }
    public void set_spaces(int row, int space) {
        this.row=row;
	this.space=space;
	if(spaces!=null)
		spaces=null;
	spaces=new int [this.row][this.space];
	number_of_seats=row*space;
    }
    public int get_number() {
        return number;
    }
    public int get_number_of_seats() {
        return number_of_seats;
    }
    public void view_spaces() {
        if(space<25)
	{
            System.out.print("RZAD");
            for(int i=0;i<space/2+1;i++)
			if(i==space/2)
				System.out.print("EKRAN");
			else
				System.out.print("  ");
		for(int i=0;i<row;i++)
		{
                    System.out.println();
                    if (i<9)
                        System.out.print(i+1+"    ");
                    else 
                        System.out.print(i+1+"   ");
			for(int j=0;j<space;j++)
			{
				System.out.print(" ");
				if(spaces[i][j]==1)
                                    if(j<9)
                                        System.out.print(" ");
                                    else
                                        System.out.print("  ");
                                else 
                                    System.out.print(j+1);
			}
		}
		System.out.println();
                System.out.println();
                System.out.println();
	}
	else
	{
            System.out.print("RZAD");
		for(int i=0;i<(space/2+4);i++)
			if(i==(space/2+3))
				System.out.print("EKRAN");
			else
				System.out.print("  ");
		for(int i=0;i<row;i++)
		{
                    System.out.println();
                    System.out.print(i+1);
                    System.out.print("   ");
			for(int j=0;j<space;j++)
			{
				if((j==7)||(j==space-6))
				System.out.print("   ");
				if(spaces[i][j]==1)
                                    if(j<9)
                                        System.out.print(" ");
                                    else
                                        System.out.print("  ");
                                else 
                                    System.out.print(j+1);
			}
		}
		System.out.println();
                System.out.println();
                System.out.println();
	}
    }
    public void take_seat(int row[], int space[],int number_seats) {
        for(int i=0;i<number_seats;i++)
		spaces[row[i]][space[i]]=1;
    }
    public void relase_seat(int row[], int space[], int number_seats) {
        for(int i=0;i<number_seats;i++)
		spaces[row[i]][space[i]]=0;
    }
    public boolean place_free(int row,int place) {
        return (spaces[row][place]==0);
    }  
}