/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication2;

/**
 *
 * @author Maciej
 */
public class JavaApplication2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Posilek posilek;
        posilek= new Posilek(256,"kanapka");
        System.out.println(posilek.get_name());
        System.out.print(" kalorie: ");
        System.out.println(posilek.get_cal());
        Kolacja kolacja=new Kolacja();
        kolacja.set_name("Kiełbasa");
        kolacja.set_cal(500);
        kolacja.set_hour(18);
        kolacja.set_minute(25);
        System.out.print("Posiłek: ");
        System.out.println(kolacja.get_name());
        System.out.print("kalorie: ");
        System.out.println(kolacja.get_cal());
        System.out.print("Godzina: ");
        System.out.print(kolacja.get_hour());
        System.out.print(":");
        System.out.println(kolacja.get_minute());
        kolacja=null;
        posilek=null;
    }
    
}
