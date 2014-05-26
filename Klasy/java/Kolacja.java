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

public class Kolacja extends Posilek{
    private int hour;
    private int minute;
    public Kolacja()
    {
        hour = 0;
        minute=0;
    }
    public Kolacja(Kolacja kolacja)
    {
        hour = kolacja.hour;
        minute=kolacja.minute;
    }
    protected void finalize()
    {
    }
    public int get_hour()
    {
        return hour;
    }
    public int get_minute()
    {
        return minute;
    }
    public void set_hour(int hour)
    {
        this.hour=hour;
    }
    public void set_minute(int minute)
    {
        this.minute=minute;
    }
}
