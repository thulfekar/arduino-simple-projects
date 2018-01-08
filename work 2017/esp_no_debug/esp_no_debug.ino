#include <SoftwareSerial.h>
SoftwareSerial esp8266(2, 3);//ESP TX  Arduino's pin 2
int a, b, c, d ;             // ESP RX  Arduino's pin 3
String aa, bb, cc, dd ;
void setup()
{
  Serial.begin(9600);
  esp8266.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  sendData("AT+RST\r\n", 2000); // reset module
  sendData("AT+CWMODE=2\r\n", 1000); // configure as access point
  sendData("AT+CIFSR\r\n", 1000); // get ip address
  sendData("AT+CIPMUX=1\r\n", 1000); // configure for multiple connections
  sendData("AT+CIPSERVER=1,80\r\n", 1000); // turn on server on port 80
}

void loop()
{
  a = analogRead(A0);
  b = analogRead(A1);
  c = analogRead(A2);
  d = analogRead(A3);
  aa = String(a);
  bb = String(b);
  cc = String(c);
  dd = String(d);

  if (esp8266.available()) // check if the esp is sending a message
  {
    if (esp8266.find("+IPD,"))
    {
      delay(1000);

      int connectionId = esp8266.read() - 48; // subtract 48 because the read() function returns
      // the ASCII decimal value and 0 (the first decimal number) starts at 48


      String webpage = "<!-- #######  YAY, I AM THE SOURCE EDITOR! #########-->
<h1 style="color: #5e9ca0;">You can edit <span style="color: #2b2301;">this demo</span> text!</h1>
<h2 style="color: #2e6c80;">How to use the editor:</h2>
<p>Paste your documents in the visual editor on the left or your HTML code in the source editor in the right. <br />Edit any of the two areas and see the other changing in real time.&nbsp;</p>
<p>Click the <span style="background-color: #2b2301; color: #fff; display: inline-block; padding: 3px 10px; font-weight: bold; border-radius: 5px;">Clean</span> button to clean your source code.</p>
<h2 style="color: #2e6c80;">Some useful features:</h2>
<ol style="list-style: none; font-size: 14px; line-height: 32px; font-weight: bold;">
<li style="clear: both;"><img style="float: left;" src="https://html-online.com/img/01-interactive-connection.png" alt="interactive connection" width="45" /> Interactive source editor</li>
<li style="clear: both;"><img style="float: left;" src="https://html-online.com/img/02-html-clean.png" alt="html cleaner" width="45" /> HTML Cleaning</li>
<li style="clear: both;"><img style="float: left;" src="https://html-online.com/img/03-docs-to-html.png" alt="Word to html" width="45" /> Word to HTML conversion</li>
<li style="clear: both;"><img style="float: left;" src="https://html-online.com/img/04-replace.png" alt="replace text" width="45" /> Find and Replace</li>
<li style="clear: both;"><img style="float: left;" src="https://html-online.com/img/05-gibberish.png" alt="gibberish" width="45" /> Lorem-Ipsum generator</li>
<li style="clear: both;"><img style="float: left;" src="https://html-online.com/img/6-table-div-html.png" alt="html table div" width="45" /> Table to DIV conversion</li>
</ol>
<p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</p>
<h2 style="color: #2e6c80;">Cleaning options:</h2>
<table class="editorDemoTable">
<thead>
<tr>
<td>Name of the feature</td>
<td>Example</td>
<td>Default</td>
</tr>
</thead>
<tbody>
<tr>
<td>Remove tag attributes</td>
<td><img style="margin: 1px 15px;" src="images/smiley.png" alt="laughing" width="40" height="16" /> (except <strong>img</strong>-<em>src</em> and <strong>a</strong>-<em>href</em>)</td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Remove inline styles</td>
<td><span style="color: green; font-size: 13px;">You <strong style="color: blue; text-decoration: underline;">should never</strong>&nbsp;use inline styles!</span></td>
<td><strong style="font-size: 17px; color: #2b2301;">x</strong></td>
</tr>
<tr>
<td>Remove classes and IDs</td>
<td><span id="demoId">Use classes to <strong class="demoClass">style everything</strong>.</span></td>
<td><strong style="font-size: 17px; color: #2b2301;">x</strong></td>
</tr>
<tr>
<td>Remove all tags</td>
<td>This leaves <strong style="color: blue;">only the plain</strong> <em>text</em>. <img style="margin: 1px;" src="images/smiley.png" alt="laughing" width="16" height="16" /></td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Remove successive &amp;nbsp;s</td>
<td>Never use non-breaking spaces&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;to set margins.</td>
<td><strong style="font-size: 17px; color: #2b2301;">x</strong></td>
</tr>
<tr>
<td>Remove empty tags</td>
<td>Empty tags should go!</td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Remove tags with one &amp;nbsp;</td>
<td>This makes&nbsp;no sense!</td>
<td><strong style="font-size: 17px; color: #2b2301;">x</strong></td>
</tr>
<tr>
<td>Remove span tags</td>
<td>Span tags with <span style="color: green; font-size: 13px;">all styles</span></td>
<td><strong style="font-size: 17px; color: #2b2301;">x</strong></td>
</tr>
<tr>
<td>Remove images</td>
<td>I am an image: <img src="images/smiley.png" alt="laughing" /></td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Remove links</td>
<td><a href="https://html-online.com">This is</a> a link.</td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Remove tables</td>
<td>Takes everything out of the table.</td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Replace table tags with structured divs</td>
<td>This text is inside a table.</td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Remove comments</td>
<td>This is only visible in the source editor <!-- HELLO! --></td>
<td><strong style="font-size: 17px; color: #2b2301;">x</strong></td>
</tr>
<tr>
<td>Encode special characters</td>
<td><span style="color: red; font-size: 17px;">&hearts;</span> <strong style="font-size: 20px;">☺ ★</strong> &gt;&lt;</td>
<td><strong style="font-size: 17px; color: #2b2301;">x</strong></td>
</tr>
<tr>
<td>Set new lines and text indents</td>
<td>Organize the tags in a nice tree view.</td>
<td>&nbsp;</td>
</tr>
</tbody>
</table>
<p><strong>&nbsp;</strong></p>
<p><strong>Save this link into your bookmarks and share it with your friends. It is all FREE! </strong><br /><strong>Enjoy!</strong></p>
<p><strong>&nbsp;</strong></p>";

      String cipSend = "AT+CIPSEND=";
      cipSend += connectionId;
      cipSend += ",";
      cipSend += webpage.length();
      cipSend += "\r\n";
      sendData(cipSend, 1000);
      sendData(webpage, 1000);

      webpage = "<h1>GAS3 = " + cc + "......" + "GAS4 = " + dd + "</h1>";
      cipSend = "AT+CIPSEND=";
      cipSend += connectionId;
      cipSend += ",";
      cipSend += webpage.length();
      cipSend += "\r\n";
      sendData(cipSend, 1000);
      sendData(webpage, 1000);
      String closeCommand = "AT+CIPCLOSE=";
      closeCommand += connectionId; // append connection id
      closeCommand += "\r\n";
      sendData(closeCommand, 3000);
    }
  }
}


String sendData(String command, const int timeout)
{
  String response = "";
  esp8266.print(command); // send the read character to the esp8266
  long int time = millis();
  while ( (time + timeout) > millis())
  {
    while (esp8266.available())
    {
      char c = esp8266.read(); // read the next character.
      response += c;
    }
  }
  return response;
}
