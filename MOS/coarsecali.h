void setuppagedraw()
{
 //DRAW UI
      if(firstdraw == false)
      {
        // UI Draw Automatic
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
        tft.println("TT:");
        
           tft.setCursor(0, 160);
        tft.setTextColor(WHITE); 
        tft.setTextSize(3);
        tft.println("TC:");
        
    tft.fillRect(0, 240, BOXSIZE, BOXSIZE, GREEN);
    tft.fillRect(0, 285, BOXSIZE, BOXSIZE, RED);
    // DT up and down
    tft.fillRect(60, 240, BOXSIZE, BOXSIZE, GREEN);
    tft.fillRect(60, 285, BOXSIZE, BOXSIZE, RED);
    // DC up and down    
    tft.fillRect(120, 240, BOXSIZE, BOXSIZE, GREEN);
    tft.fillRect(120, 285, BOXSIZE, BOXSIZE, RED);
    // TT up and down    
    tft.fillRect(120, 240, BOXSIZE, BOXSIZE, GREEN);
    tft.fillRect(120, 285, BOXSIZE, BOXSIZE, RED);
    
    tft.fillRect(190, 260, BOXSIZE, BOXSIZE, YELLOW);
      }
        //Data Draw Automatic
       
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
      
        if(!(tt == ott) || firstdraw == false)
      {
         tft.setCursor(1.52*BOXSIZE,100);
        tft.setTextColor(WHITE , BLACK); 
        tft.setTextSize(6);
        tft.println(tt,1);
        ott = tt;
      }
      
        if(!(tc == otc) || firstdraw == false)
      {
         tft.setCursor(1.52*BOXSIZE,150);
        tft.setTextColor(WHITE , BLACK); 
        tft.setTextSize(6);
        tft.println(tc,1);
        otc = tc;
      }
      
      // Handle Touch Automatic
      if(touchbox(190, 190 + BOXSIZE, 260, 260 + BOXSIZE))
      {
        currentpage = 0;
        Serial.println("you touched me that tickles");
        tft.fillScreen(BLACK);
        firstdraw = false;
        return;
      }
    // first color boxes + and -
    if(touchbox(0, 0 + BOXSIZE, 240, 240 + BOXSIZE))
    {
        dt = dt + .01;
        Serial.println("you touched me that tickles");
    }
    if(touchbox(0, 0 + BOXSIZE, 285, 285 + BOXSIZE))
    {
        dt = dt - .01;
        Serial.println("you touched me that tickles");
    }
    
    if(touchbox(60, 60 + BOXSIZE, 240, 240 + BOXSIZE))
    {
        dc = dc + .01;
        Serial.println("you touched me that tickles");
    }
    if(touchbox(60, 60 + BOXSIZE, 285, 285 + BOXSIZE))
    {
        dc = dc - .01;
        Serial.println("you touched me that tickles");
    }
    
      if(touchbox(120, 120 + BOXSIZE, 240, 240 + BOXSIZE))
    {
        tt = tt + 1;
        Serial.println("you touched me that tickles");
    }
    if(touchbox(120, 120 + BOXSIZE, 285, 285 + BOXSIZE))
    {
        tt = tt - 1;
        Serial.println("you touched me that tickles");
    }
    
    
    firstdraw = true;
}

