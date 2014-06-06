/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Maciej
 */
public class Reservation {
    private int reservation_number;
    private int seans_id;
    private int [] row;
    private int [] space;
    private int number;
    private static int number_of_reservation=0;

    public Reservation(){
        row=null;
	space=null;
	seans_id=0;
	reservation_number=0;
	number=0;
    }
    public Reservation(int seans_id,int reservation_number,int number, int row[],int space[]){
        this.seans_id=seans_id;
        this.reservation_number=reservation_number;
        this.number=number;
        this.row= new int [number];
        this.space= new int [number];
        for(int i=0;i<number;i++)
        {
            this.row[i]=row[i];
            this.space[i]=space[i];
        }
    }
    public Reservation(Reservation reservation){
        this.number=reservation.number;
        this.reservation_number=reservation.reservation_number;
        this.row=reservation.row;
        this.space=reservation.space;
        this.seans_id=reservation.seans_id;
    }
    @Override
    protected void finalize(){
            row=null;
            space=null;
        }
	
    public static int get_number_of_reservation(){
        return number_of_reservation;
    }
    public static void plus_number_of_reservation(){
        number_of_reservation++;
    }
    public static void minus_number_of_reservation(){
        number_of_reservation--;
    }
    
    public void set_seans_id(int seans_id){
        this.seans_id=seans_id;
    }
    public int get_number(){
        return this.number;
    }
    public int get_reservation_number(){
        return this.reservation_number;
    }
    public int get_seans_id(){
        return this.seans_id;
    }
    public int [] get_row(){
        return this.row;
    }
    public int [] get_space(){
        return this.space;
    }
    public int get_row(int r){
        return this.row[r];
    }
    public int get_space(int s){
        return this.space[s];
    }
}
