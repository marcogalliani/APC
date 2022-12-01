#include <iostream>
#include <random>

#include "Clustering.h"

Clustering::Clustering (unsigned int dimensions, unsigned int n_points,
                        unsigned int k_cluster, unsigned int max_iterations)
  : p (dimensions), n (n_points), k (k_cluster), max_it (max_iterations)
{

  //Now we have to create the data structure

  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution (0.0, MAX_COORD);

  std::vector<Point *> all_pointers_points; //vectors of pointers to point that we will arbitrarly assign to cluster 0


  //generate random points for each pointers
  for (unsigned i = 0; i < n; ++i)
    {
      //Generate n random points
      // Generate random coordinates
      std::vector<double> coords;


      for (unsigned j = 0; j < p; ++j)
        coords.push_back (distribution (generator));


      // Generate a new Point
      points.push_back (coords);
      labels.push_back (0); // assign every point to class 0
      all_pointers_points.push_back(& points[i]);  // store current point address
    }

  //p is the numper of pointers to points (i.e. the number of points)
  const std::vector<double> origin (p, 0);

  // Create and intialize centroids to origin
  for (unsigned i = 0; i < k; ++i)
    centers.push_back (origin);

  // Assign all points to cluster 0 (first row of the clusters vector of vectors of pointers to points)
  clusters.push_back(all_pointers_points);

  // Create and initialize other clusters to nulls
  for (unsigned i = 1; i < k; ++i)
    clusters.push_back ({nullptr});

  //I'm exiting the constructor with all points assigned to the first cluster and all the other clusters with null
  //pointers
}




void
Clustering::print (void) const
{
  // Print points and labels
  for (std::size_t i = 0; i < points.size (); ++i)
    {
      points[i].print ();
      std::cout << " : ";
      std::cout << labels[i];
      std::cout << std::endl;
    }
}

void
Clustering::calc_cluster (void)
{
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution (0, k - 1);



  //Randomly initialize labels
  /* Your code goes here */
  int random_int  = distribution (generator);


  for (auto it = labels.begin (); it != labels.end (); ++it ) {
      *it = distribution(&generator);
  }

  bool term_cond = false;
  unsigned i;

  for (i = 0; i < max_it && ! term_cond; ++i)
    {
      /* Your code goes here */
      f_labels_type  old_labels(labels);

      // update clusters according to new labels
      /* Your code goes here */
      clusters_type  new_clusters(k); //create a vector of k null pointers

      // update centroids
      for(size_t j=0; j<points.size();j++)
          new_clusters[labels[j]].push_back(&points[j]);

      // assign points to new centroids
      swap(clusters,new_clusters);

      //recompute coordinates
        for (size_t j = 0; j <centers.size() ; ++j)
            centers[j].update_coords((clusters[j]));

      //assign points to new centroids
        for (size_t j = 0; j < points.size(); ++j)
            labels[j] = min_dist_index(points[j]);

      //update terminating condition
      term_cond = old_labels==labels;
    }

  std::cout << "Number of iterations: " << i << std::endl;
  std::cout << "Final result!" << std::endl;
  print_labels ();
  std::cout << std::endl;
}

unsigned int
Clustering::min_dist_index (const Point & point) const
{
  int min_dist_ind = 0;
  //minimum distance to a center
  double min_dist = point.distance (centers[0]);

  for (std::size_t i = 1; i < centers.size (); ++i)
    {
      const double dist = point.distance (centers[i]);
      if (dist < min_dist)
        {
          min_dist = dist;
          min_dist_ind = i;
        }
    }

  return min_dist_ind;
}

void
Clustering::print_labels (void) const
{
  for (auto it = labels.begin (); it != labels.end (); ++it)
    {
      std::cout << *it << " ";
    }
}

void
Clustering::print_centers (void) const
{
  std::cout << "Centers size: ";
  std::cout << centers.size ();
  std::cout << std::endl;

  for (std::size_t i = 0; i < centers.size (); ++i)
    centers[i].print ();
}

void
Clustering::print_clusters (void) const
{
    for (unsigned i = 0; i < k; ++i)
    {
        std::cout << "Cluster: " <<  i << std::endl;
        for (Point* c: clusters[i])
        {
            c -> print ();
            std::cout << std::endl;
        }
    }
}
