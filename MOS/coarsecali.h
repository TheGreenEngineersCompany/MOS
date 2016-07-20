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
        tft.println("AA:");
        
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
    // TT up and down    
    tft.fillRect(120, 240, BOXSIZE, BOXSIZE, GREEN);
    tft.fillRect(120, 285, BOXSIZE, BOXSIZE, RED);
    // AACali up and down    
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
      
        if(!(aa == oaa) || firstdraw == false)// display analog amplifier nex to tomerpature tag
      {
         tft.setCursor(1.52*BOXSIZE,50);
        tft.setTextColor(WHITE , BLACK); 
        tft.setTextSize(6);
        tft.println(aa,1);
        oaa = aa;
        if(aa > 0)
        {
          EEPROM.write(1,0);
          EEPROM.write(2,aa);
        }
        else
        {
          EEPROM.write(1,1);
          EEPROM.write(2,-aa);
        }
      }
      
        if(!(tt == ott) || firstdraw == false)// display temperature target next to temperature target tag
      {
         tft.setCursor(1.52*BOXSIZE,100);
        tft.setTextColor(WHITE , BLACK); 
        tft.setTextSize(6);
        tft.println(tt,1);
        ott = tt;
        EEPROM.write(0,tt); // saves your temperature target to eeprom address 0
      }
       if(!(tc == otc) || firstdraw == false) //display temperature curret next to temperature current tag
      {
         tft.setCursor(1.52*BOXSIZE,150);
        tft.setTextColor(WHITE , BLACK); 
        tft.setTextSize(6);
        tft.println(tc,0);
        otc = tc;
      }

      
      // Handle Touch Automatic
      if(touchbox(190, 190 + BOXSIZE, 260, 260 + BOXSIZE)) // touch handler for page change
      {
        currentpage = 0;
        Serial.println("you touched me that tickles");
        tft.fillScreen(BLACK);
        firstdraw = false;
        delay(500);
        return;
      }

      
    // first color boxes + and -
    if(touchbox(0, 0 + BOXSIZE, 240, 240 + BOXSIZE)) // touch handler for dt +
    {
        dt = dt + .01;
        Serial.println("you touched me that tickles");
    }
    if(touchbox(0, 0 + BOXSIZE, 285, 285 + BOXSIZE)) // touch handler for dt -
    {
        dt = dt - .01;
        Serial.println("you touched me that tickles");
    }

   
    if(touchbox(60, 60 + BOXSIZE, 240, 240 + BOXSIZE))
    {
        aa = aa + 1;
        Serial.println("you touched me that tickles");
    }
    if(touchbox(60, 60 + BOXSIZE, 285, 285 + BOXSIZE))
    {
        aa = aa - 1;
        Serial.println("you touched me that tickles");
    }
    
    
      if(touchbox(120, 120 + BOXSIZE, 240, 240 + BOXSIZE))// touch handler for tt +
    {
        tt = tt + 1;
        Serial.println("you touched me that tickles");
    }
    if(touchbox(120, 120 + BOXSIZE, 285, 285 + BOXSIZE))// touch handler for tt-
    {
        tt = tt - 1;
        Serial.println("you touched me that tickles");
    }
    
    
    firstdraw = true;
}

