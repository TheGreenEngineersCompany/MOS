void statuspagedraw()
{
  //tft.setRotation(1);
  //UI DRAW
    
    //Automatic Mode
      if(firstdraw == false)
      {
        // UI Draw
        tft.setCursor(0, 7.5);
        tft.setTextColor(WHITE); 
        tft.setTextSize(3);
        tft.println("DT:");
        
        tft.setCursor(0, 60);
        tft.setTextColor(WHITE); 
        tft.setTextSize(3);
        tft.println("DC:");
        
        tft.setCursor(0, 110);
        tft.setTextColor(WHITE); 
        tft.setTextSize(3);
        tft.println("EXT:");
        
         tft.setCursor(0, 160);
        tft.setTextColor(WHITE); 
        tft.setTextSize(3);
        tft.println("HTR:");
    
         tft.setCursor(0, 267.5);
        tft.setTextColor(WHITE); 
        tft.setTextSize(3);
        tft.println("Configure:");
        
        tft.fillRect(190, 260, BOXSIZE, BOXSIZE, YELLOW);
        
         if(motoron == 1)
         {
            tft.fillRect(190, 110, BOXSIZE, BOXSIZE, GREEN);
         }
         else
         {
           tft.fillRect(190, 110, BOXSIZE, BOXSIZE, RED);
         }
          if(heateron == 1)
         {
            tft.fillRect(190, 160, BOXSIZE, BOXSIZE, GREEN);
         }
         else
         {
           tft.fillRect(190, 160, BOXSIZE, BOXSIZE, RED);
         }
        
      }
        //Data Draw
       
        if(!(dt == odt) || firstdraw == false)
      {
       tft.setCursor(1.52*BOXSIZE,0);
      tft.setTextColor(WHITE , BLACK); 
      tft.setTextSize(6);
      tft.println(dt,2);
      odt = dt;
      }
      
      if(!(dc == odc) || firstdraw == false)
      {
         tft.setCursor(1.52*BOXSIZE,50);
        tft.setTextColor(WHITE , BLACK); 
        tft.setTextSize(6);
        tft.println(dc,2);
        odc = dc;
      }
         if(firstdraw == false)
      {
         tft.setCursor(1.75*(BOXSIZE),100);
        tft.setTextColor(WHITE , BLACK); 
        tft.setTextSize(6);
        if(motoron == 0)
        {
          tft.println("OFF");
        }
        if(motoron == 1)
        {
          tft.println("ON");
        }
      }
       if(firstdraw == false)
      {
         tft.setCursor(1.75*BOXSIZE,150);
        tft.setTextColor(WHITE , BLACK); 
        tft.setTextSize(6);
         if(heateron == 0)
        {
          tft.println("OFF");
        }
        if(heateron == 1)
        {
          tft.println("ON");
        }
      }
    firstdraw = true;
  //HANDLE TOUCH
     if(touchbox(190, 190 + BOXSIZE, 260, 260 + BOXSIZE))
    {
      currentpage = 1;
        Serial.println("you touched me that tickles");
        tft.fillScreen(BLACK);
        firstdraw = false;
    }
     if(touchbox(190, 190 + BOXSIZE, 110, 110 + BOXSIZE))
    {
        if(motoron == 1)
        {
           motoron = 0;
           ms = 0;
        }
        else
        {
           motoron = 1; 
           ms = 100;
        }
        tft.fillScreen(BLACK);
        firstdraw = false;
    }
      if(touchbox(190, 190 + BOXSIZE, 160, 160 + BOXSIZE))
    {
        if(heateron == 1)
        {
           heateron = 0;
           
        }
        else
        {
           heateron = 1; 
        }
        tft.fillScreen(BLACK);
        firstdraw = false;
    }
}

