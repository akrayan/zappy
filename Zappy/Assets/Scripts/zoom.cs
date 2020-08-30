using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class zoom : MonoBehaviour {
    public Texture newSprite;
    public GameObject Sphere;
	public void change ()
    {
        Vector3 position = new Vector3(-15, 0, 141);
        Quaternion rotate = Quaternion.Euler(10, 200, 100);
        Sphere.GetComponent<Renderer>().material.mainTexture = newSprite;
        Sphere.transform.SetPositionAndRotation(position, rotate);
    }
}

