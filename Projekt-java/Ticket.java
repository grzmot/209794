/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Maciej
 */
public class Ticket {
    private double[][] ticket=new double [2][3];
    
    public Ticket(){
        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
                ticket[i][j]=0;
    }
    public Ticket(double normal_2D, double normal_3D, double reduced_2D, double reduced_3D, double group_2D,double group_3D){
        ticket[0][0]=normal_2D;
	ticket[1][0]=normal_3D;
	ticket[0][1]=reduced_2D;
	ticket[1][1]=reduced_3D;
	ticket[0][2]=group_2D;
	ticket[1][2]=group_3D;
    }
    @Override
    protected void finalize(){
        ticket=null;
    }
    public void set_normal_2D(double normal_2D) {
        ticket[0][0]=normal_2D;
    }
    public void set_normal_3D(double normal_3D){
        ticket[1][0]=normal_3D;
    }
    public void set_reduced_2D(double reduced_2D){
        ticket[0][1]=reduced_2D;
    }
    public void set_reduced_3D(double reduced_3D){
        ticket[1][1]=reduced_3D;
    }
    public void set_group_2D(double group_2D){
        ticket[0][2]=group_2D;
    }
    public void set_group_3D(double group_3D){
        ticket[1][2]=group_3D;
    }
    public double get_normal_2D(){
        return ticket[0][0];
    }
    public double get_normal_3D(){
        return ticket[1][0];
    }
    public double get_reduced_2D(){
        return ticket[1][0];
    }
    public double get_reduced_3D(){
        return ticket[1][1];
    }
    public double get_group_2D(){
        return ticket[2][0];
    }
    public double get_group_3D(){
        return ticket[2][1];
    }
    public void view_price_ticket(){
        System.out.println();
        System.out.println("Bilet Normalny-2D: "+ticket[0][0]+"zł");
        System.out.println("Bilet Normalny-3D: "+ticket[1][0]+"zł");
        System.out.println("Bilet Ulgowy-2D: "+ticket[0][1]+"zł");
        System.out.println("Bilet Ulgowy-3D: "+ticket[1][1]+"zł");
        System.out.println("Bilet Grupowy-2D: "+ticket[0][2]+"zł");
        System.out.println("Bilet Grupowy-3D: "+ticket[1][2]+"zł");
    }
}
