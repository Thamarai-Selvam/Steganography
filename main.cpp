#include "coverimage.h"
#include "secretmessage.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
    //cout << sizeof(char);
    CoverImage *newImage = new CoverImage("lena_gray.jpg");
    SecretMessage *newSecret = new SecretMessage("kami benci kurt angle arrgh geramnye apesal tak dapat ni uhhh nak kena ankle lock ni busuk betul la woi");

    int msgLength = newSecret->getSecretLength();
    int blocks = newImage->getTotalBlocks();

	for(int i = 0; i < blocks; i++)
	{
        newImage->setBlockFDCT(i, false);
	}

    unsigned char letter; //to store current msg
    int idBlock = 0; //Current block id
    int offset = 0; //current location of zigzag scan

    int zigzagloc[26]; //Middle Frequency
    for(offset = 0; offset < 26; ++offset)
    {
        zigzagloc[offset] = offset + 10;
    }
    offset = 0;
    int bit = 7; //bit counter
    int temp = 0;

	//idBlock = 123;
    //Hiding Text
    for(int i = 0; i < msgLength; i++)
    {
        letter = newSecret->getSecretCharAt(i);
        for(bit = 7; bit >= 0; --bit)
        {
            int b = (letter >> bit) & 1;
            temp = newImage->getZigZagDCTVal(idBlock, zigzagloc[offset]);
            if(temp == 1 || temp == -1 || temp == 0) //Don't embed
            {
                if(bit < 7)
                    ++bit; //Restart back the bit value
                ++offset;
                if(offset == 26)
                {
                    ++idBlock;
                    offset = 0;
                }
            }
            else
            {
                temp = (char)((temp & 0xFE) | b);
				cout << temp << "\n";
                newImage->setZigZagDCTVal(idBlock,zigzagloc[offset],temp);
                ++offset;
                if(offset == 26)
                {
                    ++idBlock;
                    offset = 0;
                }
            }
			if(bit == 0)
				++idBlock;
        }
    }

	//for(int i = 0; i < blocks; i++)
 //   {
 //       newImage->setBlockIDCT(i, false);
 //   }

 //   newImage->constructNewImage("new.bmp");
	//newImage->~CoverImage();

	//CoverImage *newImage2 = new CoverImage("new.bmp");

    //for(int i = 0; i < blocks; i++)
    //{
    //    newImage->setBlockFDCT(i, false);
    //}

    //Extracting Text
    idBlock = 0;
    offset = 0;
	vector <char> msg(msgLength);

    for(int b = 0; b < msgLength; ++b)
    {
        for(int i = 0; i < 8; ++i)
        {
            temp = newImage->getZigZagDCTVal(idBlock, zigzagloc[offset]);
            if(temp == 1 || temp == -1 || temp == 0) //Don't bother this value
            {
                if (i > 0)
                    --i; //Restart back the bit counter
                ++offset;
                if(offset == 26)
                {
                    offset = 0;
                    ++idBlock;
                }
            }
            else
            {
                msg.at(b) = (char)((msg.at(b)) << 1 | (temp & 1));
                ++offset;
                if(offset == 26)
                {
                    ++idBlock;
                    offset = 0;
                }
            }
			if(i == 7)
				++idBlock;
        }
    }

    for(int i = 0; i < msgLength; i++)
    {
		cout << msg.at(i);
    }
}

