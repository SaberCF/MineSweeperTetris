class Sound
{

public:

    long musicn;

    unsigned long sBlank;
    unsigned long sWin;
    unsigned long sLose;
    unsigned long sError;
    unsigned long sLeft;
    unsigned long sRight;
    unsigned long sFlag;
    unsigned long sNew;
    unsigned long sSolve;
    unsigned long sMusic[10];

    bool soundb = true;
    bool musicb = true;
    long musici = -256;
    double musictime;

    Sound();
    void initsound();
    void initmusic();
    void playsound(long id);
    void switchsound();
    void playmusic();
    void checkmusic();
    void switchmusic();

};

Sound::Sound()
{
    musicn = 4;
}

void Sound::initsound()
{
    initmusic();
    playmusic();
}

void Sound::initmusic()
{
    sWin = loadaudio("./wav/Win.wav");
    sLose = loadaudio("./wav/Lose.wav");
    sError = loadaudio("./wav/Error.wav");
    sLeft = loadaudio("./wav/Left.wav");
    sRight = loadaudio("./wav/Right.wav");
    sFlag = loadaudio("./wav/Flag.wav");
    sNew = loadaudio("./wav/New.wav");
    sSolve = loadaudio("./wav/Solve.wav");
    sMusic[0] = loadaudio("./mid/music1.mid", " type sequencer");
    sMusic[1] = loadaudio("./mid/music2.mid", " type sequencer");
    sMusic[2] = loadaudio("./mid/music3.mid", " type sequencer");
    sMusic[3] = loadaudio("./mid/music4.mid", " type sequencer");
}

void Sound::playsound(long id)
{
    if (soundb)
    {
        setaudiopos(id, 0);
    }
}

void Sound::switchsound()
{
    soundb = !soundb;
    if (soundb)
    {
        setaudiopos(sLeft, 0);
    }
}

void Sound::playmusic()
{
    if (musicb)
    {
        if (iswin())
        {
            if (musici == -256)
            {
                musici = 0;
            }
            else
            {
                long musici_ = rand() % (musicn - 1);
                if (musici_ >= musici)
                {
                    musici_++;
                }
                musici = musici_;
            }
            musictime = gettimer();
        }
        else
        {
            musici = -256;
            musictime = 0;
        }
        setaudiopos(sMusic[musici], 0);
    }
}

void Sound::checkmusic()
{
    if (musicb)
    {
        if (gettimer() > musictime)
        {
            if (getaudiopos(sMusic[musici]) < getaudiolen(sMusic[musici]))
            {
                musictime += 10;
            }
            else
            {
                playmusic();
            }
        }
    }
}

void Sound::switchmusic()
{
    musicb = !musicb;
    if (musicb)
    {
        playmusic();
    }
    else
    {
        stopaudio(sMusic[musici]);
    }
    if (soundb)
    {
        setaudiopos(sLeft, 0);
    }
}
