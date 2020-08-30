using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Select : MonoBehaviour {

    public Game GameManager;
    // Use this for initialization

    void OnMouseDown()
    {
        if (tag == "Tile")
        {
            Tile tile;

            tile.Inventory = new int[7];
            int i = -1, j = -1;

            while (++j < GameManager.Mapy)
            {
                i = -1;
                while (++i < GameManager.Mapx)
                {
                    if (GameManager.Map[j][i].Cube == gameObject)
                        tile = GameManager.Map[j][i];
                }
            }
            GameManager.SelectOnScreen.isOn = IsOn.TILE;
            GameManager.SelectOnScreen.x = i;
            GameManager.SelectOnScreen.y = j;
            //if (tile.Inventory)
            GameManager.SelectOnScreen.inventory = tile.Inventory;
        }
        else if (tag == "Player")
        {
            Player p;

            p.inventory = new int[7];
            int i = -1;

            while (GameManager.Players[++i].perso != gameObject) ;
            p = GameManager.Players[i];
            GameManager.SelectOnScreen.isOn = IsOn.PLAYER;
            GameManager.SelectOnScreen.id = p.id;
            //if (tile.Inventory)
            GameManager.SelectOnScreen.inventory = p.inventory;
        }
    }
}
