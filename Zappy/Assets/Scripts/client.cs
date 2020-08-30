using System;
using System.Net.Sockets;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;

public class Client : MonoBehaviour
{

    public string Ip;
    public int Port;
    public GameObject GameM;
    public Game GameManager;
    public bool Load;
    private NetworkStream stream;
    private TcpClient ClientTcp;
    private char[] sspace = { ' ' };
    private char[] sline = { '\n' };

    byte[] string_to_byte(string s)
    {
        int i;
        byte[] b = new byte[s.Length];
        i = -1;
        while (++i < s.Length)
            b[i] = (byte)s[i];
        return (b);
    }

    // Use this for initialization*/
    void Start()
    {
        Game_info gi;

        Load = false;
        gi = GameObject.Find("Static").GetComponent<Game_info>();
        Ip = gi.Ip;
        Port = gi.Port;
        GameManager = GetComponent<Game>();
        ClientTcp = new TcpClient(Ip, Port);
        stream = ClientTcp.GetStream();
        stream.Write(string_to_byte("GRAPHIC\n"), 0, 8);

        GameManager.SelectOnScreen.isOn = IsOn.NOTHING;
        GameManager.Players = new List<Player>();
        GameManager.Teams = new List<Team>();
<<<<<<< HEAD
=======
        GameManager.Eggs = new List<Egg>();
>>>>>>> master
        Load = true;
    }


    // Update is called once per frame
    void Update()
    {
        string s;
        string[] arg;
        string[] cmd;
        byte[] by = new byte[4096];

        if (Load && stream.DataAvailable)
        {
            int i;

            stream.Read(by, 0, 4096);
            s = System.Text.Encoding.Default.GetString(by);
            Debug.Log(s);
            cmd = s.Split(sline);
            i = -1;
            while (++i < cmd.Length - 1)
            {
                arg = cmd[i].Split(sspace);
                if (arg[0] == "msz")
                    msz(arg);
                else if (arg[0] == "bct")
                    bct(arg);
                else if (arg[0] == "tna")
                    tna(arg);
                else if (arg[0] == "pnw")
                    pnw(arg);
                else if (arg[0] == "ppo")
                    ppo(arg);
                else if (arg[0] == "plv")
                    plv(arg);
                else if (arg[0] == "pin")
                    pin(arg);
                else if (arg[0] == "pex")
                    pex(arg);
                else if (arg[0] == "pbc")
                    pbc(arg);
                else if (arg[0] == "pie")
                    pie(arg);
                else if (arg[0] == "pfk")
                    pfk(arg);
                else if (arg[0] == "pic")
                    pic(arg);
                else if (arg[0] == "pdr")
                    pdr(arg);
                else if (arg[0] == "pgt")
                    pgt(arg);
                else if (arg[0] == "pdi")
                    pdi(arg);
                else if (arg[0] == "enw")
                    enw(arg);
                else if (arg[0] == "eht")
                    eht(arg);
                else if (arg[0] == "ebo")
                    ebo(arg);
                else if (arg[0] == "edi")
                    edi(arg);
                else if (arg[0] == "sgt")
                    sgt(arg);
                else if (arg[0] == "seg")
                    seg(arg);

            }
        }
    }

    void msz(string[] arg)
    {
        if (arg.Length == 3)
        {
            GameManager.Mapx = Int32.Parse(arg[1]);
            GameManager.Mapy = Int32.Parse(arg[2]);
            GameManager.initMap();
        }
    }

    void bct(string[] arg)
    {
        int x, y, i;

        if (arg.Length == 10)
        {
            i = -1;
            x = Int32.Parse(arg[1]);
            y = Int32.Parse(arg[2]);
            if (x >= 0 && x < GameManager.Mapx && y >= 0 && y < GameManager.Mapy)
                while (++i < 7)
                {
                    GameManager.Map[y][x].Inventory[i] = int.Parse(arg[i + 3]);
                }
                GameManager.load_tile(GameManager.Map[y][x]);
        }
    }

    void tna(string[] arg)
    {
        if (arg.Length == 2)
        {
            Team team;

<<<<<<< HEAD
            team.color.a = 1;
=======
            team.color.a = //new Color(UnityEngine.Random.Range(0f, 0.98f), UnityEngine.Random.Range(0f, 0.98f), UnityEngine.Random.Range(0f, 0.98f), 1);
>>>>>>> master
            team.color.r = 0;
            team.color.g = 0;
            team.color.b = 0;
            while (team.color.r + team.color.g + team.color.b < 1.5)
            {
<<<<<<< HEAD
                team.color.r = UnityEngine.Random.Range(0, 1);
                team.color.g = UnityEngine.Random.Range(0, 1);
                team.color.b = UnityEngine.Random.Range(0, 1);
=======
                team.color.r = UnityEngine.Random.Range(0f, 1);
                team.color.g = UnityEngine.Random.Range(0f, 1);
                team.color.b = UnityEngine.Random.Range(0f, 1);
>>>>>>> master
            }
            team.name = arg[1];
            GameManager.Teams.Add(team);
        }
    }

    void pnw(string[] arg)
    {
        if (arg.Length == 7)
        {
            int i;
            Player p;
            Vector3 pos;

            p.id = Int32.Parse(arg[1]);
            p.x = Int32.Parse(arg[2]);
            p.y = Int32.Parse(arg[3]);
            p.dir = (Int32.Parse(arg[4]) - 1) * 90;
            p.lvl = Int32.Parse(arg[5]);
            p.inventory = new int[7];
            p.team = arg[6];
            p.state = "Stand By";

            pos = GameManager.Map[p.y][p.x].Cube.transform.position;
            pos.y = 0.6f;
            p.perso = Instantiate(GameManager.Persos[p.lvl - 1], pos, Quaternion.Euler(0, p.dir, 0), GameManager.Plist);
<<<<<<< HEAD
            p.perso.GetComponent<Animator>().speed = GameManager.Frequency;
            GameManager.Players.Add(p);
            i = -1;
            while (GameManager.Teams[i].name != p.team) ;
            p.perso.GetComponent<Renderer>().material.color = GameManager.Teams[i].color;
=======
            Destroy(Instantiate(GameManager.Effects[0], p.perso.transform), 2);
            p.perso.GetComponent<Animator>().speed = GameManager.Frequency;
            p.perso.GetComponent<Select>().GameManager = GameManager;
            GameManager.Players.Add(p);
            i = -1;
            while (GameManager.Teams[++i].name != p.team);
            p.perso.GetComponentInChildren<Renderer>().material.color = GameManager.Teams[i].color;
>>>>>>> master
        }
    }

    void ppo(string[] arg)
    { 
        if (arg.Length == 5)
        {
            Player p;
            Player n;
            Vector3 pos;
            int i;

            p.id = Int32.Parse(arg[1]);
            p.x = Int32.Parse(arg[2]);
            p.y = Int32.Parse(arg[3]);
            p.dir = (Int32.Parse(arg[4]) - 1) * 90;

            i = -1;
            while (++i < GameManager.Players.Count && GameManager.Players[i].id != p.id) ;
            if (i == GameManager.Players.Count)
                return;
            if (GameManager.Players[i].dir != p.dir)
            {
                p.lvl = GameManager.Players[i].lvl;
                p.team = GameManager.Players[i].team;
                p.perso = GameManager.Players[i].perso;
                p.state = GameManager.Players[i].state;
                p.inventory = GameManager.Players[i].inventory;
                StartCoroutine(rotate(7 / GameManager.Frequency, p, i));
                //n = GameManager.Players[i];
                //n.dir = p.dir;
                
            }
            else if (GameManager.Players[i].x != p.x || GameManager.Players[i].y != p.y)
            {
                if (Mathf.Abs(GameManager.Players[i].x - p.x) > 1 || Mathf.Abs(p.y - GameManager.Players[i].y) > 1)
                {
                    p.lvl = GameManager.Players[i].lvl;
                    p.team = GameManager.Players[i].team;
                    p.perso = GameManager.Players[i].perso;
                    p.state = GameManager.Players[i].state;
                    p.inventory = GameManager.Players[i].inventory;
                    //p = GameManager.Players[i];
                    GameManager.Players[i] = p;
                    pos = GameManager.Map[p.y][p.x].Cube.transform.position;
                    pos.y = 0.6f;
                    StartCoroutine(tp(7 / GameManager.Frequency, p, pos));
                    
                }
                else
                {
                    p.lvl = GameManager.Players[i].lvl;
                    p.team = GameManager.Players[i].team;
                    p.perso = GameManager.Players[i].perso;
                    p.state = GameManager.Players[i].state;
                    p.inventory = GameManager.Players[i].inventory;
                    GameManager.Players[i] = p;
                    pos = GameManager.Map[p.y][p.x].Cube.transform.position;
<<<<<<< HEAD
                    pos.y += 1;
=======
                    pos.y = 0.6f;
>>>>>>> master
                    // p.perso.transform.Translate((pos - p.perso.transform.position), 0);
                    StartCoroutine(forward(7 / GameManager.Frequency, p, pos));
                }
            }
        }
    }

    public IEnumerator tp(float time, Player p, Vector3 pos)
    {
        GameObject effect1;
        GameObject effect2;

        effect1 = Instantiate(GameManager.Effects[1], p.perso.transform);
        effect2 = Instantiate(GameManager.Effects[0], pos, Quaternion.identity);
        yield return new WaitForSeconds(time);
        p.perso.transform.position = pos;
        Destroy(effect1);
        Destroy(effect2);
    }

    public IEnumerator rotate(float time, Player p, int i)
    {
        float t;

        t = 0;
        while (t < time)
        {
            p.perso.transform.Rotate(new Vector3(0, (p.dir - GameManager.Players[i].perso.transform.rotation.eulerAngles.y) * Time.deltaTime / time, 0));
            //tran.Translate(dist * Time.deltaTime / time, 0, 0);
            t += Time.deltaTime;
            yield return new WaitForSeconds(Time.deltaTime);
        }
        GameManager.Players[i] = p;
    }

    public IEnumerator forward(float time, Player p, Vector3 pos)
    {
        float t;
        Vector3 old = p.perso.transform.position;

        p.perso.GetComponent<Animator>().SetBool("Walk", true);
        t = 0;
        while (t < time)
        {
<<<<<<< HEAD
            p.perso.transform.Translate((pos - old), 0);
=======
            p.perso.transform.Translate((pos - old) * Time.deltaTime / time, 0);
>>>>>>> master
            //tran.Translate(dist * Time.deltaTime / time, 0, 0);
            t += Time.deltaTime;
            yield return new WaitForSeconds(Time.deltaTime);
        }
        p.perso.GetComponent<Animator>().SetBool("Walk", false);
    }

    void plv(string[] arg)
    {
        if (arg.Length == 3)
        {
            int id;
            int i;
            int lvl;
            Vector3 pos;
            Player p;

            id = Int32.Parse(arg[2]);
            lvl = Int32.Parse(arg[3]);
            i = -1;
            while (++i < GameManager.Players.Count && GameManager.Players[i].id != id) ;
            if (i == GameManager.Players.Count)
                return;
            p = GameManager.Players[i];
            Destroy(p.perso);
            p.id = id;
            p.lvl = lvl;
            pos = GameManager.Map[p.y][p.x].Cube.transform.position;
            pos.y = 0.6f;
            Destroy(Instantiate(GameManager.Effects[2], p.perso.transform), 2);
            p.perso = Instantiate(GameManager.Persos[p.lvl - 1], pos, Quaternion.Euler(0, p.dir, 0), GameManager.Plist);
            i = -1;
<<<<<<< HEAD
            while (GameManager.Teams[i].name != p.team) ;
            p.perso.GetComponent<Renderer>().material.color = GameManager.Teams[i].color;
=======
            while (GameManager.Teams[++i].name != p.team) ;
            p.perso.GetComponentInChildren<Renderer>().material.color = GameManager.Teams[i].color;
>>>>>>> master
        }
    }

    void pin(string[] arg)
    {
        if (arg.Length == 10)
        {
            int i;
            int j;
            int id;

            i = -1;
            id = Int32.Parse(arg[1]);
            while (++i < GameManager.Players.Count && GameManager.Players[i].id != id) ;
            if (i == GameManager.Players.Count)
                return;
            j = -1;
            while (++j < 7)
            {
                GameManager.Players[i].inventory[j] = int.Parse(arg[j + 4]);
            }
        }
    }

    void pex(string[] arg)
    {
        if (arg.Length == 2)
        {
            int i;
            int id;

            id = Int32.Parse(arg[1]);
            i = -1;
            while (GameManager.Players[++i].id != id) ;
            GameManager.Players[i].perso.GetComponent<Animator>().SetTrigger("Eject");
<<<<<<< HEAD
=======
            Destroy(Instantiate(GameManager.Effects[3], GameManager.Players[i].perso.transform), 2);
>>>>>>> master
        }
    }

    void pbc(string[] arg)
    {
        if (arg.Length == 2)
        {
            int i;
            int id;
            string msg;

            id = Int32.Parse(arg[1]);
            msg = arg[2];
            i = -1;
            while (GameManager.Players[++i].id != id) ;
            GameManager.Players[i].perso.GetComponent<Animator>().SetTrigger("Name");
        }
    }

    void pic(string[] arg)
    {
        if (arg.Length > 5)
        {
            int i;
            int j;
            int id;
            Player p;

            i = 3;
            while (++i < arg.Length)
            {
                id = Int32.Parse(arg[i]);
                j = -1;
                while (GameManager.Players[j].id != id);
                p = GameManager.Players[Int32.Parse(arg[j])];
<<<<<<< HEAD
=======
                Destroy(Instantiate(GameManager.Effects[4], p.perso.transform.position, p.perso.transform.rotation), 300 / GameManager.Frequency);
>>>>>>> master
                StartCoroutine(incant(300 / GameManager.Frequency, p, p.x, p.y));
            }
        }
    }

    public IEnumerator incant(float time, Player p, int x, int y)
    {
        float t;
        Vector3 old = p.perso.transform.position;

        p.perso.GetComponent<Animator>().SetBool("incant", true);
        t = 0;
        while (t < time)
        {
            if (p.perso.GetComponent<Animator>().GetBool("Walk"))
                p.perso.GetComponent<Animator>().SetBool("incant", false);
            if (p.x == x && p.y == y)
                p.perso.GetComponent<Animator>().SetBool("incant", true);
            //tran.Translate(dist * Time.deltaTime / time, 0, 0);
            t += Time.deltaTime;
            yield return new WaitForSeconds(Time.deltaTime);
        }
        p.perso.GetComponent<Animator>().SetBool("Walk", false);
    }

    void pie(string[] arg)
    {
        if (arg.Length == 2)
        {
        }
    }

    void pfk(string[] arg)
    {
        if (arg.Length == 2)
        {
            int i;
            int id;

            id = Int32.Parse(arg[1]);
            i = -1;
            while (GameManager.Players[++i].id != id) ;
            StartCoroutine(laying(42 / GameManager.Frequency, GameManager.Players[i]));
        }
    }

    public IEnumerator laying(float time, Player p)
    {
        Destroy(Instantiate(GameManager.Effects[5], p.perso.transform.position, p.perso.transform.rotation), time);
        p.perso.GetComponent<Animator>().SetBool("Magic", true);
        yield return new WaitForSeconds(time);
        p.perso.GetComponent<Animator>().SetBool("Magic", false);
    }


    void pdr(string[] arg)
    {
   
            if (arg.Length == 3)
            {
                int i;
                int j;
                int id;

                id = Int32.Parse(arg[1]);

                i = -1;
                while (GameManager.Players[++i].id != id) ;
                j = Int32.Parse(arg[2]);
                GameManager.Players[i].inventory[j] = GameManager.Players[i].inventory[j] - 1;
                GameManager.Players[i].perso.GetComponent<Animator>().SetTrigger("Take");
            }
        
    }

    void pgt(string[] arg)
    {
        if (arg.Length == 3)
        {
            int i;
            int j;
            int id;

            id = Int32.Parse(arg[1]);
            
            i = -1;
            while (GameManager.Players[++i].id != id) ;
            j = Int32.Parse(arg[2]);
            GameManager.Players[i].inventory[j] = GameManager.Players[i].inventory[j] + 1;
            GameManager.Players[i].perso.GetComponent<Animator>().SetTrigger("Take");
        }
    }


    void pdi(string[] arg)
    {
        if (arg.Length == 2)
        {
            int i;
            int id;

            id = Int32.Parse(arg[1]);

            i = -1;
            while (GameManager.Players[++i].id != id) ;
            GameManager.Players[i].perso.GetComponent<Animator>().SetTrigger("Dead");
            StartCoroutine(dead(4 / GameManager.Frequency, GameManager.Players[i]));
        }
    }

    public IEnumerator dead(float time, Player p)
    {
        yield return new WaitForSeconds(time);
        Destroy(Instantiate(GameManager.Effects[6], p.perso.transform.position, p.perso.transform.rotation), 2);
        Destroy(p.perso);
        GameManager.Players.Remove(p);
    }

    void enw(string[] arg)
    {
        if (arg.Length == 5)
        {
            Egg egg;
            Vector3 pos;


            egg.id = Int32.Parse(arg[1]);
            egg.x = Int32.Parse(arg[3]);
            egg.y = Int32.Parse(arg[4]);
            pos = GameManager.Map[egg.y][egg.x].Cube.transform.position;
            pos.y = 0.6f;
            egg.perso = egg.perso = Instantiate(GameManager.EPrefab, pos, Quaternion.identity, GameManager.Elist);
            GameManager.Eggs.Add(egg);
        }
    }

    void eht(string[] arg)
    {
        if (arg.Length == 2)
        {
        }
    }

    void ebo(string[] arg)
    {
        if (arg.Length == 2)
        {
            int i;
            int id;

            id = Int32.Parse(arg[1]);

            i = -1;
            while (GameManager.Eggs[++i].id != id) ;
            Destroy(GameManager.Eggs[i].perso);
            GameManager.Eggs.Remove(GameManager.Eggs[i]);
        }
    }

    void edi(string[] arg)
    {
        if (arg.Length == 2)
        {
        }
    }

    void sgt(string[] arg)
    {
        int i;

        if (arg.Length == 2)
        {

            GameManager.Frequency = Int32.Parse(arg[1]);
            i = -1;
            while (++i < GameManager.Players.Count)
            {
                GameManager.Players[i].perso.GetComponent<Animator>().speed = GameManager.Frequency;
            }
        }
    }

    void seg(string[] arg)
    {
        if (arg.Length == 2)
        {
        }
    }

}