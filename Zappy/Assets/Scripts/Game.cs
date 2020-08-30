using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Game : MonoBehaviour {

    public GameObject[] Persos;
    public GameObject[] Items;
    public GameObject[] Cubes;
    public GameObject[] Effects;
    public GameObject EPrefab;
    public Tile[][] Map;
    public int Mapx = -1;
    public int Mapy = -1;
    public float Frequency = 1;
    public List<Team> Teams;
    public List<Player> Players;
    public List<Egg> Eggs;
    public Transform Map_t;
    public Transform Plist;
    public Transform Elist;
    public Transform Camera;
    public float Space = 0;
    public LookAt SelectOnScreen;

    public void initMap()
    {
        Vector3 pcam;
        Vector3 pos = new Vector3(0, 0, 0);
        int i;
        int j;

        j = -1;
        Map = new Tile[Mapy][];
        while (++j < Mapy)
        {
            Map[j] = new Tile[Mapx];
            i = -1;
            while (++i < Mapx)
            {
                pos.x = i * (1 + Space);
                pos.z = -j * (1 + Space);
                Map[j][i].Inventory = new int[7];
                Map[j][i].Cube = Instantiate(Cubes[(i + j) % Cubes.Length], pos, Quaternion.identity, Map_t);
                Map[j][i].Cube.GetComponent<Select>().GameManager = GetComponent<Game>();
            }
            pcam.x = Mapx / 2;
            pcam.z = (-Mapy / 2) - 5;
            pcam.y = 3;
            Camera.transform.position = pcam;
        }
    }

    public void load_tile(Tile t)
    {
        int i, j;
        Vector3 pos;
        Vector3 pos2;

        i = t.Cube.transform.childCount;
        while (--i >= 0)
            Destroy(t.Cube.transform.GetChild(i).gameObject);
        pos = t.Cube.transform.position;
        pos.y = 0.55f;
        i = -1;
        while (++i < 7)
        {
            
            j = -1;
            while (++j < t.Inventory[i])
            {
                pos2 = pos;
                pos2.x = Random.Range(pos.x - 0.5f, pos.x + 0.5f);
                pos2.z = Random.Range(pos.z - 0.5f, pos.z + 0.5f);
                Instantiate(Items[i], pos2, Quaternion.identity, t.Cube.transform);
            }
        }
    }
    // Use this for initialization
    void Start () {

	}
	
	// Update is called once per frame
	void Update () {
		
	}

}

public struct Player
{
    public int x;
    public int y;
    public int dir;

    public int id;

    public string team;
    public string state;
    public int lvl;
    public int[] inventory;

    public GameObject perso;
}

public struct Egg
{
    public int x;
    public int y;

    public int id;
    public GameObject perso;
}

public struct Tile
{
    public int[] Inventory;

    public GameObject Cube;
}

public struct Team
{
    public string name;
    public Color color;
<<<<<<< HEAD
=======
}

public struct LookAt
{
    public IsOn isOn;
    public int[] inventory;

    public int x;
    public int y;

    public int id;
}

public enum IsOn
{
    NOTHING,
    PLAYER,
    TILE
>>>>>>> master
}