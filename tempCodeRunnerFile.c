
                    break;
                case 3:
                    ShowBrochure();
                    break;
                case 4:
                    ExitProgram();
                    exit(0);
                    break;
                default:
                    printf("Not a valid input at this stage\n");
            }
        }
        else if(currentstate==loggedin)
        {
        system("CLS");
        printf("\n\t\t\t\t=========================");
		printf("\n\t\t\t\t PARV  Tourisms ");
		printf("\n\t\t\t\t=========================\n");
            printf("\n\t\t\t\tBook Package - 1\n\t\t\t\tCheck Ticket - 2\n\t\t\t\tPrint Ticket - 3\n\t\t\t\tCancel Ticket - 4\n\t\t\t\tChange Password - 5"
                   "\n\t\t\t\tLogout User - 6\n\t\t\t\tBrochure - 7\n\t\t\t\tExit - 8\n");
            scanf("%d",&ch2);
            switch(ch2)
            {
                case 1:
                    BookTicket(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 2:
                    CheckTicket(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 3:
                    PrintTicket(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 4:
                    CancelTicket(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 5:
                    ChangePassword(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 6:
                    LogoutUser(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 7:
                    ShowBrochure();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 8:
                    ExitProgram();
                    exit(0);
                    break;
                default:
                    printf("Not a valid input at this stage\n");
            }
        }
    }
    return 0;
}

user* InitializeList(user *h)
{
    user* t,*ptr,temp;
    FILE *fp;
    int cc=0,x;
    float ff;
    fp=fopen("users.txt","r");

    if(fp==NULL)
        return NULL;

    if(fgetc(fp)==EOF)
        return NULL;

    rewind(fp);
	while(fscanf(fp,"%s %s %s %f %d",temp.username,temp.password,temp.place,&temp.price,&temp.numtick)!=EOF)
	{
		ptr=(user*)malloc(sizeof(user));
		strcpy(ptr->username,temp.username);
		strcpy(ptr->password,temp.password);
		strcpy(ptr->place,temp.place);
		ptr->price=temp.price;
		ptr->numtick=temp.numtick;
		ptr->next=NULL;

		if(h==NULL)
            h=t=ptr;
		else
		{
			h->next=ptr;
			h=ptr;
		}
	}
	fclose(fp);
    return t;
}

void WriteToFile(user *h)
{
    FILE *fp;
    fp=fopen("users.txt","w");
    while(h!=NULL)
    {
        fprintf(fp,"%s %s %s %f %d\n",h->username,h->password,h->place,h->price,h->numtick);
        h=h->next;
    }
    fclose(fp);
}

void ShowBrochure()
{
	system("CLS");
    printf("\tPRICE LIST\n=============================\n1. IND - Traditional INDIA -  Rs 50,000.00/-\n2. AUS - Rs Kango AUSTRALIA -Rs 75,000.00/-\n3. UAE - DUBAI Dhamaka - Rs 43,000.00/-\n4. MDV - Waterry MALDIVES - Rs 62,000.00/-\n"
           "5. 