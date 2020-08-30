using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class zoomout : MonoBehaviour
{
    public Texture newSprite;
    public GameObject Sphere;
    public void changeout()
    {
        Sphere.GetComponent<Renderer>().material.mainTexture = newSprite;
    }
}
