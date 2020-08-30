using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Create_map : MonoBehaviour {

    public GameObject[] Cubes;
    public int Mapx = 20;
    public int Mapy = 20;

    // Use this for initialization
    void Start () {
        int x;
        int y;
        Vector3 pos;
        
        y = -1;
        while (++y < Mapy)
        {
            x = -1;
            while (++x < Mapx)
            {
                pos.x = x + 0.2f * x;
                pos.y = Mathf.Sin((Mathf.PI * x) / Mapx) * 5 + Mathf.Sin((Mathf.PI * y) / Mapy) * 5;
                pos.z = y + 0.2f * y;
                Instantiate(Cubes[(x + y) % Cubes.Length], pos, Quaternion.identity, transform);
            }
        }
	}

}
